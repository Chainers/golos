#pragma once

#include <steemit/chain/evaluator.hpp>
#include <steemit/chain/database.hpp>
#include <steemit/chain/proposal_object.hpp>
#include <steemit/chain/transaction_evaluation_state.hpp>

#include <steemit/protocol/operations.hpp>
#include <steemit/protocol/proposal_operations.hpp>

namespace steemit {
    namespace chain {

        class proposal_create_evaluator
                : public steemit::chain::evaluator_impl<proposal_create_evaluator> {
        public:
            typedef proposal_create_operation operation_type;

            proposal_create_evaluator(database &db)
                    : steemit::chain::evaluator_impl<proposal_create_evaluator>(db) {
            }

            void do_apply(const proposal_create_operation &o);

        protected:
            transaction _proposed_trx;
        };

        class proposal_update_evaluator
                : public steemit::chain::evaluator_impl<proposal_update_evaluator> {
        public:
            typedef proposal_update_operation operation_type;

            proposal_update_evaluator(database &db)
                    : steemit::chain::evaluator_impl<proposal_update_evaluator>(db) {
            }

            void do_apply(const proposal_update_operation &o);

        protected:
            const proposal_object *_proposal = nullptr;
            processed_transaction processed_transaction;
            bool executed_proposal = false;
            bool proposal_failed = false;
        };

        class proposal_delete_evaluator
                : public steemit::chain::evaluator_impl<proposal_delete_evaluator> {
        public:
            typedef proposal_delete_operation operation_type;

            proposal_delete_evaluator(database &db)
                    : steemit::chain::evaluator_impl<proposal_delete_evaluator>(db) {

            }

            void do_apply(const proposal_delete_operation &);
        protected:

            const proposal_object *_proposal = nullptr;
        };

    }
} // graphene::chain
