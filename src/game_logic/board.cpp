#include "../../headers/game_logic/board.hpp"

// Constructors
Board::Board()
{
    for (unsigned int row = 0; row < BOARD_ROWS; row++)
    {
        for (unsigned int column = 0; column < BOARD_COLUMNS; column++)
        {
            fields[row][column] = std::make_shared<Field>();
        }
    }
}

Board::Board(FieldsArray fields)
{
    this->fields = fields;
}
// Constructors end

FieldsArray Board::getFields() const
{
    return this->fields;
}

unsigned int Board::getRowsNumber() const
{
    return BOARD_ROWS;
}

unsigned int Board::getColumnsNumber() const
{
    return BOARD_COLUMNS;
}

std::shared_ptr<Field> Board::getFieldByCoordinate(unsigned int row, unsigned int column) const
{
    if (row >= this->getRowsNumber() || column >= this->getColumnsNumber())
    {
        throw std::invalid_argument("X value has to be less than width and Y value has to be less than length");
    }
    return this->fields.at(row).at(column);
}

std::vector<std::shared_ptr<Field>> Board::getFieldsWithHeroes() const
{
    std::vector<std::shared_ptr<Field>> fieldsWithHeroes;
    for (auto row : this->fields)
    {
        for (auto field : row)
        {
            if (!field->isFree())
            {
                fieldsWithHeroes.push_back(field);
            }
        }
    }
    return fieldsWithHeroes;
}

std::vector<std::shared_ptr<Field>> Board::getFieldsWithBubbleBooster() const
{
    std::vector<std::shared_ptr<Field>> fieldsWithBubbleBooster;
    for (auto row : this->fields)
    {
        for (auto field : row)
        {
            if (field->isBubbleBoosted() == true)
            {
                fieldsWithBubbleBooster.push_back(field);
            }
        }
    }
    return fieldsWithBubbleBooster;
}

std::vector<std::shared_ptr<Field>> Board::getFieldsWithFieldBooster() const
{
    std::vector<std::shared_ptr<Field>> fieldsWithFieldBooster;
    for (auto row : this->fields)
    {
        for (auto field : row)
        {
            if (field->isFieldBoosted() == true)
            {
                fieldsWithFieldBooster.push_back(field);
            }
        }
    }
    return fieldsWithFieldBooster;
}

std::tuple<int, int> Board::findFieldCoordinates(std::shared_ptr<Field> field) const
{
    for (unsigned int row = 0; row < BOARD_ROWS; row++)
    {
        for (unsigned int column = 0; column < BOARD_COLUMNS; column++)
        {
            auto fieldToCompare = this->getFieldByCoordinate(row, column);
            if (field == fieldToCompare)
            {
                return std::make_tuple<int, int>((int)row, (int)column);
            }
        }
    }
    return std::make_tuple<int, int>(-1, -1);
}

std::vector<std::shared_ptr<Field>> Board::getFieldsAround(std::shared_ptr<Field> field) const
{
    std::vector<std::shared_ptr<Field>> fieldsAround;
    auto fieldCoordinates = findFieldCoordinates(field);
    unsigned int row = std::get<0>(fieldCoordinates);
    unsigned int column = std::get<1>(fieldCoordinates);
    if (row > 0)
    {
        fieldsAround.push_back(getFieldByCoordinate(row - 1, column));
        if (column > 0)
        {
            fieldsAround.push_back(getFieldByCoordinate(row, column - 1));
            fieldsAround.push_back(getFieldByCoordinate(row - 1, column - 1));
        }
        if (column < (BOARD_COLUMNS - 1))
        {
            fieldsAround.push_back(getFieldByCoordinate(row - 1, column + 1));
        }
    }
    if (row < (BOARD_ROWS - 1))
    {
        fieldsAround.push_back(getFieldByCoordinate(row + 1, column));
        if (column > 0)
        {
            fieldsAround.push_back(getFieldByCoordinate(row + 1, column - 1));
        }
        if (column < (BOARD_COLUMNS - 1))
        {
            fieldsAround.push_back(getFieldByCoordinate(row, column + 1));
            fieldsAround.push_back(getFieldByCoordinate(row + 1, column + 1));
        }
    }
    return fieldsAround;
}
