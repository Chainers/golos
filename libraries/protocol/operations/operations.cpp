#include <steemit/protocol/operations/operations.hpp>

#include <steemit/protocol/operations/operation_utilities_impl.hpp>

namespace steemit {
    namespace protocol {

        struct is_market_op_visitor {
            typedef bool result_type;

            template<typename T>
            bool operator()(T &&v) const {
                return false;
            }

            template<uint8_t Major, uint8_t Hardfork, uint16_t Release>
            bool operator()(const limit_order_create_operation<Major, Hardfork, Release> &) const {
                return true;
            }

            template<uint8_t Major, uint8_t Hardfork, uint16_t Release>
            bool operator()(const limit_order_create2_operation<Major, Hardfork, Release> &) const {
                return true;
            }

            template<uint8_t Major, uint8_t Hardfork, uint16_t Release>
            bool operator()(const limit_order_cancel_operation<Major, Hardfork, Release> &) const {
                return true;
            }

            template<uint8_t Major, uint8_t Hardfork, uint16_t Release>
            bool operator()(const call_order_update_operation<Major, Hardfork, Release> &) const {
                return true;
            }

            template<uint8_t Major, uint8_t Hardfork, uint16_t Release>
            bool operator()(const bid_collateral_operation<Major, Hardfork, Release> &) const {
                return true;
            }

            template<uint8_t Major, uint8_t Hardfork, uint16_t Release>
            bool operator()(const transfer_operation<Major, Hardfork, Release> &) const {
                return true;
            }

            template<uint8_t Major, uint8_t Hardfork, uint16_t Release>
            bool operator()(const transfer_to_vesting_operation<Major, Hardfork, Release> &) const {
                return true;
            }
        };

        bool is_market_operation(const operation &op) {
            return op.visit(is_market_op_visitor());
        }

        struct is_vop_visitor {
            typedef bool result_type;

            template<typename T>
            bool operator()(const T &v) const {
                return v.is_virtual();
            }
        };

        bool is_virtual_operation(const operation &op) {
            return op.visit(is_vop_visitor());
        }

    }
} // steemit::protocol

namespace fc {

    void to_variant(const steemit::protocol::operation &var, fc::variant &vo) {
        var.visit(from_operation<versioned_from_operation_policy>(vo));
    }

    void from_variant(const fc::variant &var, steemit::protocol::operation &vo) {
        static std::map<string, uint32_t> to_tag = []() {
            std::map<string, uint32_t> name_map;
            for (int i = 0; i < steemit::protocol::operation::count(); ++i) {
                steemit::protocol::operation tmp;
                tmp.set_which(i);
                string n;
                tmp.visit(get_operation_name(n));
                name_map[n] = i;
            }
            return name_map;
        }();

        auto ar = var.get_array();
        if (ar.size() < 2) {
            return;
        }
        if (ar[0].is_uint64()) {
            vo.set_which(ar[0].as_uint64());
        } else {
            std::string operation_name = steemit::version::state::instance().current_version.hardfork() <= 16 ? (
                    boost::format(ar[0].as_string().append("<%1%, %2%, %3%>")) % 0 % 16 % 0).str() : (
                                                 boost::format(ar[0].as_string().append("<%1%, %2%, %3%>")) %
                                                 steemit::version::state::instance().current_version.major() %
                                                 steemit::version::state::instance().current_version.hardfork() %
                                                 steemit::version::state::instance().current_version.release()).str();
            auto itr = to_tag.find(operation_name);
            FC_ASSERT(itr != to_tag.end(), "Invalid operation name: ${n}", ("n", ar[0]));
            vo.set_which(to_tag[operation_name]);
        }
        vo.visit(fc::to_static_variant(ar[1]));
    }
}

namespace steemit {
    namespace protocol {
        void operation_validate(const operation &op) {
            op.visit(steemit::protocol::operation_validate_visitor());
        }

        void operation_get_required_authorities(const operation &op, flat_set<protocol::account_name_type> &active,
                                                flat_set<protocol::account_name_type> &owner,
                                                flat_set<protocol::account_name_type> &posting,
                                                std::vector<authority> &other) {
            op.visit(steemit::protocol::operation_get_required_auth_visitor(active, owner, posting, other));
        }
    }
}

#include <steemit/protocol/operations/asset_operations.tpp>
#include <steemit/protocol/operations/comment_operations.tpp>
#include <steemit/protocol/operations/escrow_operations.tpp>
#include <steemit/protocol/operations/market_operations.tpp>
#include <steemit/protocol/operations/steem_operations.tpp>
#include <steemit/protocol/operations/account_operations.tpp>
#include <steemit/protocol/operations/transfer_operations.tpp>
#include <steemit/protocol/operations/proposal_operations.tpp>