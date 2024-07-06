#include <gtest/gtest.h>
#include "../Gestion_parentesis.h"
#include <string>
#include <vector>

TEST(GestionParentesisTest, CadenaValida1) {
    const std::string input = "(hola)(que)(tal)";
    std::vector<std::string> expected = {"hola", "que", "tal"};
    EXPECT_EQ(GestionParentesis(input), expected);
}

TEST(GestionParentesisTest, CadenaValida2) {
    const std::string input = "((hola)(que))(tal)";
    std::vector<std::string> expected = {"(hola)(que)", "tal"};
    EXPECT_EQ(GestionParentesis(input), expected);
}

TEST(GestionParentesisTest, NoIniciaConParentesis) {
    const std::string input = "hola(que)(tal)";
    EXPECT_THROW(GestionParentesis(input), std::invalid_argument);
}

TEST(GestionParentesisTest, ParentesisNoBalanceados) {
    const std::string input = "(hola)(que(tal)";
    EXPECT_THROW(GestionParentesis(input), std::invalid_argument);
}

TEST(GestionParentesisTest, NoTerminaConParentesisCerrado) {
    const std::string input = "(hola)(que))(tal";
    EXPECT_THROW(GestionParentesis(input), std::invalid_argument);
}

TEST(GestionParentesisTest, ParentesisVacios) {
    const std::string input = "(hola)()";
    EXPECT_THROW(GestionParentesis(input), std::invalid_argument);
}

TEST(GestionParentesisTest, TextoFueraDeParentesis) {
    const std::string input = "(hola)que(tal)";
    EXPECT_THROW(GestionParentesis(input), std::invalid_argument);
}
