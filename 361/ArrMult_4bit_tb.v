
`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////
////////
// Company: CSULB
// Engineer: Amin Rezaei
// Create Date: 08/22/2020 06:59:39 PM
// Design Name: 361_Lab1
// Module Name: ArrMult_4bit_tb
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////
////////
module ArrMult_4bit_tb();
  reg [3:0] a_tb, b_tb;
  wire [7:0] prod_tb;
  ArrMult_4bit uut(.a(a_tb), .b(b_tb), .prod(prod_tb));
  
  initial begin
    a_tb = 4'b1101;
    b_tb = 4'b1001;
    #10

    a_tb = 4'b1001;
    b_tb = 4'b1101;
    #10

    a_tb = 4'b0110;
    b_tb = 4'b0111;
    #10

    a_tb = 4'b0101;
    b_tb = 4'b1010;
    #10

    a_tb = 4'b0111;
    b_tb = 4'b0011;
    #10

    a_tb = 4'b1110;
    b_tb = 4'b0111;
    #10
    $finish;
  end
endmodule
