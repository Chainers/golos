#include <steemit/chain/database/database.hpp>

#include <steemit/chain/evaluators/account_create_evaluator.hpp>
#include <steemit/chain/evaluators/account_create_with_delegation_evaluator.hpp>
#include <steemit/chain/evaluators/account_update_evaluator.hpp>
#include <steemit/chain/evaluators/account_witness_proxy_evaluator.hpp>
#include <steemit/chain/evaluators/account_witness_vote_evaluator.hpp>
#include <steemit/chain/evaluators/cancel_transfer_from_savings_evaluator.hpp>
#include <steemit/chain/evaluators/change_recovery_account_evaluator.hpp>
#include <steemit/chain/evaluators/comment_evaluator.hpp>
#include <steemit/chain/evaluators/comment_options_evaluator.hpp>
#include <steemit/chain/evaluators/comment_payout_extension_evaluator.hpp>
#include <steemit/chain/evaluators/convert_evaluator.hpp>
#include <steemit/chain/evaluators/custom_binary_evaluator.hpp>
#include <steemit/chain/evaluators/custom_evaluator.hpp>
#include <steemit/chain/evaluators/custom_json_evaluator.hpp>
#include <steemit/chain/evaluators/decline_voting_rights_evaluator.hpp>
#include <steemit/chain/evaluators/delegate_vesting_shares_evaluator.hpp>
#include <steemit/chain/evaluators/delete_comment_evaluator.hpp>
#include <steemit/chain/evaluators/escrow_approve_evaluator.hpp>
#include <steemit/chain/evaluators/escrow_dispute_evaluator.hpp>
#include <steemit/chain/evaluators/escrow_release_evaluator.hpp>
#include <steemit/chain/evaluators/escrow_transfer_evaluator.hpp>
#include <steemit/chain/evaluators/feed_publish_evaluator.hpp>
#include <steemit/chain/evaluators/limit_order_cancel_evaluator.hpp>
#include <steemit/chain/evaluators/limit_order_create2_evaluator.hpp>
#include <steemit/chain/evaluators/limit_order_create_evaluator.hpp>
#include <steemit/chain/evaluators/pow2_evaluator.hpp>
#include <steemit/chain/evaluators/pow_evaluator.hpp>
#include <steemit/chain/evaluators/prove_authority_evaluator.hpp>
#include <steemit/chain/evaluators/recover_account_evaluator.hpp>
#include <steemit/chain/evaluators/report_over_production_evaluator.hpp>
#include <steemit/chain/evaluators/request_account_recovery_evaluator.hpp>
#include <steemit/chain/evaluators/reset_account_evaluator.hpp>
#include <steemit/chain/evaluators/set_reset_account_evaluator.hpp>
#include <steemit/chain/evaluators/set_withdraw_vesting_route_evaluator.hpp>
#include <steemit/chain/evaluators/transfer_evaluator.hpp>
#include <steemit/chain/evaluators/transfer_from_savings_evaluator.hpp>
#include <steemit/chain/evaluators/transfer_to_savings_evaluator.hpp>
#include <steemit/chain/evaluators/transfer_to_vesting_evaluator.hpp>
#include <steemit/chain/evaluators/vote_evaluator.hpp>
#include <steemit/chain/evaluators/withdraw_vesting_evaluator.hpp>
#include <steemit/chain/evaluators/witness_update_evaluator.hpp>
#include <steemit/chain/evaluators/challenge_authority_evaluator.hpp>

namespace steemit {
    namespace chain {

        void database::initialize_indexes() {
            add_core_index<database_basic, dynamic_global_property_index>(*this);
            add_core_index<database_basic, witness_index>(*this);
            add_core_index<database_basic, transaction_index>(*this);
            add_core_index<database_basic, block_summary_index>(*this);
            add_core_index<database_basic, witness_schedule_index>(*this);
            add_core_index<database_basic, comment_index>(*this);
            add_core_index<database_basic, comment_vote_index>(*this);
            add_core_index<database_basic, witness_vote_index>(*this);
            add_core_index<database_basic, limit_order_index>(*this);
            add_core_index<database_basic, feed_history_index>(*this);
            add_core_index<database_basic, convert_request_index>(*this);
            add_core_index<database_basic, liquidity_reward_balance_index>(*this);
            add_core_index<database_basic, operation_index>(*this);
            add_core_index<database_basic, account_history_index>(*this);
            add_core_index<database_basic, hardfork_property_index>(*this);
            add_core_index<database_basic, withdraw_vesting_route_index>(*this);
            add_core_index<database_basic, owner_authority_history_index>(*this);
            add_core_index<database_basic, change_recovery_account_request_index>(*this);
            add_core_index<database_basic, escrow_index>(*this);
            add_core_index<database_basic, savings_withdraw_index>(*this);
            add_core_index<database_basic, decline_voting_rights_request_index>(*this);
            add_core_index<database_basic, vesting_delegation_index>(*this);
            add_core_index<database_basic, vesting_delegation_expiration_index>(*this);
            add_core_index<database_basic, reward_fund_index>(*this);
            add_core_index<database_basic, account_index>(*this);
            add_core_index<database_basic, account_authority_index>(*this);
            add_core_index<database_basic, account_bandwidth_index>(*this);
            add_core_index<database_basic, account_recovery_request_index>(*this);


            _plugin_index_signal();
        }

        void database::initialize_evaluators() {
            registry.register_evaluator<database_t, vote_evaluator>(*this);
            registry.register_evaluator<database_t, transfer_evaluator>(*this);
            registry.register_evaluator<database_t, transfer_to_vesting_evaluator>(*this);
            registry.register_evaluator<database_t, withdraw_vesting_evaluator>(*this);
            registry.register_evaluator<database_t, set_withdraw_vesting_route_evaluator>(*this);
            registry.register_evaluator<database_t, witness_update_evaluator>(*this);
            registry.register_evaluator<database_t, account_witness_vote_evaluator>(*this);
            registry.register_evaluator<database_t, account_witness_proxy_evaluator>(*this);
            registry.register_evaluator<database_t, custom_evaluator>(*this);
            registry.register_evaluator<database_t, custom_binary_evaluator>(*this);
            registry.register_evaluator<database_t, custom_json_evaluator>(*this);
            registry.register_evaluator<database_t, pow_evaluator>(*this);
            registry.register_evaluator<database_t, pow2_evaluator>(*this);
            registry.register_evaluator<database_t, report_over_production_evaluator>(*this);
            registry.register_evaluator<database_t, feed_publish_evaluator>(*this);
            registry.register_evaluator<database_t, comment_payout_extension_evaluator>(*this);
            registry.register_evaluator<database_t, convert_evaluator>(*this);
            registry.register_evaluator<database_t, challenge_authority_evaluator>(*this);
            registry.register_evaluator<database_t, prove_authority_evaluator>(*this);
            registry.register_evaluator<database_t, request_account_recovery_evaluator>(*this);
            registry.register_evaluator<database_t, recover_account_evaluator>(*this);
            registry.register_evaluator<database_t, change_recovery_account_evaluator>(*this);
            registry.register_evaluator<database_t, escrow_transfer_evaluator>(*this);
            registry.register_evaluator<database_t, escrow_approve_evaluator>(*this);
            registry.register_evaluator<database_t, escrow_dispute_evaluator>(*this);
            registry.register_evaluator<database_t, escrow_release_evaluator>(*this);
            registry.register_evaluator<database_t, transfer_to_savings_evaluator>(*this);
            registry.register_evaluator<database_t, transfer_from_savings_evaluator>(*this);
            registry.register_evaluator<database_t, cancel_transfer_from_savings_evaluator>(*this);
            registry.register_evaluator<database_t, decline_voting_rights_evaluator>(*this);
            registry.register_evaluator<database_t, reset_account_evaluator>(*this);
            registry.register_evaluator<database_t, set_reset_account_evaluator>(*this);
            registry.register_evaluator<database_t, account_create_with_delegation_evaluator>(*this);
            registry.register_evaluator<database_t, delegate_vesting_shares_evaluator>(*this);
            registry.register_evaluator<database_t, account_create_evaluator>(*this);
            registry.register_evaluator<database_t, account_update_evaluator>(*this);
            registry.register_evaluator<database_t, comment_evaluator>(*this);
            registry.register_evaluator<database_t, comment_options_evaluator>(*this);
            registry.register_evaluator<database_t, delete_comment_evaluator>(*this);
            registry.register_evaluator<database_t, limit_order_create_evaluator>(*this);
            registry.register_evaluator<database_t, limit_order_create2_evaluator>(*this);
            registry.register_evaluator<database_t, limit_order_cancel_evaluator>(*this);
        }

        void database::apply_operation(const operation &op) {
            operation_notification note(op);
            notify_pre_apply_operation(note);
            registry.get_evaluator(op).apply(op);
            notify_post_apply_operation(note);
        }

        shared_ptr<database> make_database() {
            return shared_ptr<database>(new database);
        }
    }
}