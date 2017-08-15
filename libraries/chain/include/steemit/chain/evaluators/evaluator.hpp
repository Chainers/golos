#pragma once

#include <steemit/protocol/exceptions.hpp>
#include <steemit/protocol/operations.hpp>

namespace steemit {
    namespace chain {

        template<typename OperationType=steemit::protocol::operation> class evaluator {
        public:
            virtual void apply(const OperationType &op) = 0;

            virtual int get_type() const = 0;
        };

        template<typename DataBase, typename EvaluatorType, typename OperationType=steemit::protocol::operation>
        class evaluator_impl : public evaluator<OperationType> {
        public:
            typedef OperationType operation_sv_type;
            // typedef typename EvaluatorType::operation_type op_type;

            evaluator_impl(DataBase &d) : _db(d) {
            }

            virtual void apply(const OperationType &o) final override {
                auto *eval = static_cast< EvaluatorType * >(this);
                const auto &op = o.template get<typename EvaluatorType::operation_type>();
                eval->do_apply(op);
            }

            virtual int get_type() const override {
                return OperationType::template tag<typename EvaluatorType::operation_type>::value;
            }

            DataBase &db() {
                return _db;
            }

        protected:
            DataBase &_db;
        };

    }
}