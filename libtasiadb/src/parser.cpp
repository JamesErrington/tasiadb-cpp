#include <iostream>
#include <string>

#include "parser.hpp"

namespace tasiadb {
    class Tokenizer {
    private:
        std::string::const_iterator start;
        std::string::const_iterator end;
        std::string::const_iterator current;

        char advance() {
            current = std::next(current);
            return *(current - 1);
        }

        Token tokenize_ident() {
            // @TODO: write a better keyword lookup
            while (current < end && is_ident_body(*current)) {
                current = std::next(current);
            }

            std::string_view value{start, current};

            if (value == "CREATE") {
                return { .type = TokenType::CREATE };
            }

            if (value == "TABLE") {
                return { .type = TokenType::TABLE };
            }

            if (value == "INTEGER") {
                return { .type = TokenType::INTEGER_TYPE };
            }

            if (value == "TEXT") {
                return { .type = TokenType::TEXT_TYPE };
            }

            return { .type = TokenType::IDENT, .value = value };
        }

    public:
        Tokenizer(const std::string& input) : start(input.cbegin()), end(input.cend()), current(input.cbegin()) {}

        Token next() {
            while (is_whitespace(*current)) {
                advance();
            }

            start = current;

            if (current >= end) {
                return { .type = TokenType::EOI };
            }

            auto rune = advance();
            switch (rune) {
                case '(':
                    return { .type = TokenType::OPEN_PAREN };
                case ')':
                    return { .type = TokenType::CLOSE_PAREN };
                case ',':
                    return { .type = TokenType::COMMA };
                case ';':
                    return { .type = TokenType::SEMICOLON };
            }

            if (is_ident_start(rune)) {
                return tokenize_ident();
            }

            return { .type = TokenType::ERROR };
        }
    };

    void parse(const std::string& input) {
        Tokenizer tokenizer(input);
        Token token;
        while (token = tokenizer.next(), token.type != TokenType::EOI) {
            std::cout << "Token: " << TokenTypeToString(token.type) << " (" << token.value << ")" << std::endl;
        }
    }
}
