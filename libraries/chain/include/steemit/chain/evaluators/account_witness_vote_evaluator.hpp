#ifndef GOLOS_ACCOUNT_WITNESS_VOTE_EVALUATOR_HPP
#define GOLOS_ACCOUNT_WITNESS_VOTE_EVALUATOR_HPP

#include "forward.hpp"

namespace steemit {
    namespace chain {

        class account_witness_vote_evaluator : public evaluator_impl<database_tag, account_witness_vote_evaluator> {
        public:
            typedef protocol::account_witness_vote_operation operation_type;

            template<typename DataBase>
            account_witness_vote_evaluator(DataBase &db) : evaluator_impl<database_tag, account_witness_vote_evaluator>(
                    db) {
            }

            void do_apply(const protocol::account_witness_vote_operation &o);
        };
    }
}
#endif //GOLOS_ACCOUNT_WITNESS_VOTE_EVALUATOR_HPP
