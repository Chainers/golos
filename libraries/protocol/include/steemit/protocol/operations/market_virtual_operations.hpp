#ifndef GOLOS_MARKET_VIRTUAL_OPERATIONS_HPP
#define GOLOS_MARKET_VIRTUAL_OPERATIONS_HPP

#include <steemit/protocol/asset.hpp>
#include <steemit/protocol/base.hpp>
#include <steemit/protocol/block_header.hpp>

namespace steemit {
    namespace protocol {

        /**
         * @ingroup operations
         *
         * @note This is a virtual operation that is created while matching orders and
         * emitted for the purpose of accurately tracking account history, accelerating
         * a reindex.
         */
        template<uint8_t Major, uint8_t Hardfork, uint16_t Release>
        struct fill_order_operation : public virtual_operation, public static_version<Major, Hardfork, Release> {
            fill_order_operation() {

            }

            fill_order_operation(const string &c_o, uint32_t c_id, const asset &c_p, const string &o_o, uint32_t o_id,
                                 const asset &o_p) : current_owner(c_o), current_order_id(c_id), current_pays(c_p),
                    open_owner(o_o), open_order_id(o_id), open_pays(o_p) {
            }

            account_name_type current_owner;
            integral_id_type current_order_id = 0;
            asset <Major, Hardfork, Release> current_pays;
            account_name_type open_owner;
            integral_id_type open_order_id = 0;
            asset <Major, Hardfork, Release> open_pays;
        };

        /**
         * @ingroup operations
         *
         * @note This is a virtual operation that is created while matching call orders and
         * emitted for the purpose of accurately tracking account history, accelerating
         * a reindex.
         */
        template<uint8_t Major, uint8_t Hardfork, uint16_t Release>
        struct fill_call_order_operation : public virtual_operation, public static_version<Major, Hardfork, Release> {
            fill_call_order_operation() {

            }

            fill_call_order_operation(integral_id_type o, const account_name_type &a, const asset &p, const asset &r,
                                      const asset &f) : order_id(o), owner(a), pays(p), receives(r), fee(f) {
            }

            integral_id_type order_id;
            account_name_type owner;
            asset <Major, Hardfork, Release> pays;
            asset <Major, Hardfork, Release> receives;
            asset <Major, Hardfork, Release> fee; // paid by receiving account

            pair <asset<Major, Hardfork, Release>::asset_container_type, asset<Major, Hardfork,
                    Release>::asset_container_type> get_market() const {
                return pays.symbol < receives.symbol ? std::make_pair(pays.symbol, receives.symbol) : std::make_pair(
                        receives.symbol, pays.symbol);
            }
        };

        /**
         * @ingroup operations
         *
         * @note This is a virtual operation that is created while matching call orders and
         * emitted for the purpose of accurately tracking account history, accelerating
         * a reindex.
         */
        template<uint8_t Major, uint8_t Hardfork, uint16_t Release>
        struct fill_settlement_order_operation
                : public virtual_operation, public static_version<Major, Hardfork, Release> {
            fill_settlement_order_operation() {

            }

            fill_settlement_order_operation(integral_id_type o, const account_name_type &a, const asset &p,
                                            const asset &r, const asset &f) : order_id(o), owner(a), pays(p),
                    receives(r) {
            }

            integral_id_type order_id;
            account_name_type owner;
            asset <Major, Hardfork, Release> pays;
            asset <Major, Hardfork, Release> receives;
            asset <Major, Hardfork, Release> fee; // paid by receiving account

            pair <asset<Major, Hardfork, Release>::asset_container_type, asset<Major, Hardfork,
                    Release>::asset_container_type> get_market() const {
                return pays.symbol < receives.symbol ? std::make_pair(pays.symbol, receives.symbol) : std::make_pair(
                        receives.symbol, pays.symbol);
            }
        };

        /**
         * @ingroup operations
         *
         * @note This is a virtual operation that is created while reviving a
         * bitasset from collateral bids.
         */
        template<uint8_t Major, uint8_t Hardfork, uint16_t Release>
        struct execute_bid_operation : public virtual_operation, public static_version<Major, Hardfork, Release> {
            execute_bid_operation() {
            }

            execute_bid_operation(account_name_type a, asset d, asset c) : bidder(a), debt(d), collateral(c) {
            }

            account_name_type bidder;
            asset <Major, Hardfork, Release> debt;
            asset <Major, Hardfork, Release> collateral;
        };

        typedef fc::static_variant<protocol::fill_order_operation, protocol::fill_call_order_operation,
                protocol::fill_settlement_order_operation> market_virtual_operations;
    }
}

FC_REFLECT_TYPENAME(steemit::protocol::market_virtual_operations)

FC_REFLECT(steemit::protocol::fill_order_operation,
           (current_owner)(current_order_id)(current_pays)(open_owner)(open_order_id)(open_pays))
FC_REFLECT(steemit::protocol::fill_call_order_operation, (order_id)(owner)(pays)(receives)(fee))
FC_REFLECT(steemit::protocol::fill_settlement_order_operation, (order_id)(owner)(pays)(receives)(fee))
FC_REFLECT(steemit::protocol::execute_bid_operation, (bidder)(debt)(collateral))

#endif //GOLOS_MARKET_VIRTUAL_OPERATIONS_HPP