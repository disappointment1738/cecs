
`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Amin Rezaei
// Create Date: 08/22/2020 06:59:39 PM
// Design Name: 361_Lab1
// Module Name: ArrMult_4bit
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////
module ArrMult_4bit(
  input [3:0] a, b,
  output [7:0] prod
  );
    wire [10:0] carry;
    wire [5:0] partialSum;

    //Partial Products
    wire [3:0] pp [0:3];

    //Asign Patrial Products
    //row 0
    mux2to1 m00(.a(a[0]), .b(1'b0), .sel(b[0]), .out(pp[0][0]));
    mux2to1 m01(.a(a[1]), .b(1'b0), .sel(b[0]), .out(pp[0][1]));
    mux2to1 m02(.a(a[2]), .b(1'b0), .sel(b[0]), .out(pp[0][2]));
    mux2to1 m03(.a(a[3]), .b(1'b0), .sel(b[0]), .out(pp[0][3]));
    //row 1
    mux2to1 m10(.a(a[0]), .b(1'b0), .sel(b[1]), .out(pp[1][0]));
    mux2to1 m11(.a(a[1]), .b(1'b0), .sel(b[1]), .out(pp[1][1]));
    mux2to1 m12(.a(a[2]), .b(1'b0), .sel(b[1]), .out(pp[1][2]));
    mux2to1 m13(.a(a[3]), .b(1'b0), .sel(b[1]), .out(pp[1][3]));
    //row 2
    mux2to1 m20(.a(a[0]), .b(1'b0), .sel(b[2]), .out(pp[2][0]));
    mux2to1 m21(.a(a[1]), .b(1'b0), .sel(b[2]), .out(pp[2][1]));
    mux2to1 m22(.a(a[2]), .b(1'b0), .sel(b[2]), .out(pp[2][2]));
    mux2to1 m23(.a(a[3]), .b(1'b0), .sel(b[2]), .out(pp[2][3]));
    //row 3
    mux2to1 m30(.a(a[0]), .b(1'b0), .sel(b[3]), .out(pp[3][0]));
    mux2to1 m31(.a(a[1]), .b(1'b0), .sel(b[3]), .out(pp[3][1]));
    mux2to1 m32(.a(a[2]), .b(1'b0), .sel(b[3]), .out(pp[3][2]));
    mux2to1 m33(.a(a[3]), .b(1'b0), .sel(b[3]), .out(pp[3][3]));

    //Assign Adding Circuit
    //sum 0
    assign prod[0] = pp[0][0];
    //sum 1
    HA h0(.a(pp[1][0]), .b(pp[0][1]), .c_out(carry[0]), .sum(prod[1]));
    //sum 2
    FA f0(.a(pp[1][1]), .b(pp[0][2]), .c_in(carry[0]), .c_out(carry[1]), .sum(partialSum[0]));
    HA h1(.a(pp[2][0]), .b(partialSum[0]), .c_out(carry[2]), .sum(prod[2]));
    //sum 3
    HA h2(.a(carry[2]), .b(carry[1]), .c_out(carry[3]), .sum(partialSum[1]) );
    FA f1( .a(pp[1][2]), .b(pp[0][3]), .c_in(partialSum[1]), .c_out(carry[4]), .sum(partialSum[2]) ); 
    FA f2( .a(pp[3][0]), .b(pp[2][1]), .c_in(partialSum[2]), .c_out(carry[5]), .sum(sum[3]) );
    //sum 4
    FA f3( .a(partialSum[1]), .b(carry[4]), .c_in(carry[5]), .c_out(carry[4]), .sum(partialSum[3]) ); 
    FA f4( .a(pp[2][2]), .b(pp[1][3]), .c_in(partialSum[3]), .c_out(carry[5]), .sum(partialSum[4]) );
    HA h3( .a(pp[3][1]), .b(partialSum[4]), .c_out(carry[6]), .sum(sum[4]) );
    //sum 5
    //sum 6 & sum 7
    
endmodule
