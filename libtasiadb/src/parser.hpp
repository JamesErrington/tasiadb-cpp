#ifndef LIBTASIADB_PARSER_H
#define LIBTASIADB_PARSER_H

#include <string>
#include <optional>

enum class TokenType {
    EOI,
    CREATE,
    TABLE,
    OPEN_PAREN,
    CLOSE_PAREN,
    IDENT,
    INTEGER_TYPE,
    TEXT_TYPE,
    COMMA,
    SEMICOLON,
    ERROR,
};

constexpr const char* TokenTypeToString(TokenType type) {
    switch (type) {
        case TokenType::EOI: return "EOI";
        case TokenType::CREATE: return "CREATE";
        case TokenType::TABLE: return "TABLE";
        case TokenType::OPEN_PAREN: return "OPEN_PAREN";
        case TokenType::CLOSE_PAREN: return "CLOSE_PAREN";
        case TokenType::IDENT: return "IDENT";
        case TokenType::INTEGER_TYPE: return "INTEGER_TYPE";
        case TokenType::TEXT_TYPE: return "TEXT_TYPE";
        case TokenType::COMMA: return "COMMA";
        case TokenType::SEMICOLON: return "SEMICOLON";
        case TokenType::ERROR: return "ERROR";
    }
}

struct Token {
    TokenType type;
    std::string_view value;
};

inline bool is_whitespace(char rune) {
    return rune == ' ';
}

inline bool is_ident_start(char rune) {
    return std::isalpha(rune);
}

inline bool is_ident_body(char rune) {
    return std::isalnum(rune) || rune == '_';
}

#endif /* LIBTASIADB_PARSER_H */
