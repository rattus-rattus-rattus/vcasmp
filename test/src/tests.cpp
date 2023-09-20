#include "AST.hpp"
#include "Parser.hpp"
#include "catch_amalgamated.hpp"

TEST_CASE( "parse valid declarations", "[declaration]" )
{
  Parser      p;
  Instruction inst;
  p.is_verbose = false;
  p.parse_declaration( "var = 32", inst );
  REQUIRE( inst.mnemonic == "equ" );
  REQUIRE( inst.op1.as_string() == "var" );
  REQUIRE( inst.op2.as_int() == 0x50 );
}