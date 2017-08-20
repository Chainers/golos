#ifndef GOLOS_ESCROW_RELEASE_EVALUATOR_HPP
#define GOLOS_ESCROW_RELEASE_EVALUATOR_HPP

#include "forward.hpp"

namespace steemit {
    namespace chain {

        class escrow_release_evaluator : public evaluator_impl<database_t, escrow_release_evaluator> {
        public:
            typedef protocol::escrow_release_operation operation_type;

            template<typename Database>
            escrow_release_evaluator(Database &db) : evaluator_impl<database_t, escrow_release_evaluator>(db) {
            }

            void do_apply(const protocol::escrow_release_operation &o);
        };
    }
}
#endif //GOLOS_ESCROW_RELEASE_EVALUATOR_HPP
