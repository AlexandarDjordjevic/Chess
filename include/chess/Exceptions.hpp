#pragma once

#include <exception>
#include <stdexcept>

namespace chess {

namespace exceptions {

class Invalid_move : public std::exception {
public:
    /**
     * @brief Construct a new Exception_base object
     *
     */
    Invalid_move() noexcept;

    /**
     * @brief Construct a new Exception_base object
     *
     * @param message
     */
    Invalid_move(const std::string& message) noexcept;

    /**
     * @brief Destroy the Exception_base object
     *
     */
    ~Invalid_move() override = default;

    /**
     * @brief Pointer to a string with explanatory information
     *
     * @return const char*
     */
    virtual const char* what() const noexcept override;

private:
    std::string m_message;
};

class Empty_field_selected : public std::exception {
public:
    /**
     * @brief Construct a new Exception_base object
     *
     */
    Empty_field_selected() noexcept;

    /**
     * @brief Construct a new Exception_base object
     *
     * @param message
     */
    Empty_field_selected(const std::string& message) noexcept;

    /**
     * @brief Destroy the Exception_base object
     *
     */
    ~Empty_field_selected() override = default;

    /**
     * @brief Pointer to a string with explanatory information
     *
     * @return const char*
     */
    virtual const char* what() const noexcept override;

private:
    std::string m_message;
};

class Unexpected_state : public std::exception {
public:
    /**
     * @brief Construct a new Exception_base object
     *
     */
    Unexpected_state() noexcept;

    /**
     * @brief Construct a new Exception_base object
     *
     * @param message
     */
    Unexpected_state(const std::string& message) noexcept;

    /**
     * @brief Destroy the Exception_base object
     *
     */
    ~Unexpected_state() override = default;

    /**
     * @brief Pointer to a string with explanatory information
     *
     * @return const char*
     */
    virtual const char* what() const noexcept override;

private:
    std::string m_message;
};

class Wrong_piece_selected : public std::exception {
public:
    /**
     * @brief Construct a new Exception_base object
     *
     */
    Wrong_piece_selected() noexcept;

    /**
     * @brief Construct a new Exception_base object
     *
     * @param message
     */
    Wrong_piece_selected(const std::string& message) noexcept;

    /**
     * @brief Destroy the Exception_base object
     *
     */
    ~Wrong_piece_selected() override = default;

    /**
     * @brief Pointer to a string with explanatory information
     *
     * @return const char*
     */
    virtual const char* what() const noexcept override;

private:
    std::string m_message;
};

} // namespace exceptions
} // namespace chess
