#ifndef GOLOS_WITHDRAW_VESTING_EVALUATOR_HPP
#define GOLOS_WITHDRAW_VESTING_EVALUATOR_HPP

#include "forward.hpp"

namespace steemit {
    namespace chain {

        class withdraw_vesting_evaluator : public evaluator_impl<database_tag,withdraw_vesting_evaluator> {
        public:
            typedef protocol::withdraw_vesting_operation operation_type;

            template<typename DataBase>
            withdraw_vesting_evaluator(DataBase &db) : evaluator_impl<database_tag,withdraw_vesting_evaluator>(db) {}

            void do_apply(const protocol::withdraw_vesting_operation &o);
        };
    }}
#endif //GOLOS_WITHDRAW_VESTING_EVALUATOR_HPP
