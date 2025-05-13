module adder_subtractor(
    input [3:0] A, B, 
    input mode,        // mode = 0 -> addition, mode = 1 -> subtraction
    output [3:0] S,
    output Cout
);
    wire [3:0] B_xor;  
    wire C1, C2, C3;

    assign B_xor = B ^ {4{mode}}; // XOR each bit of B with mode (if mode=1, it inverts B)
    
    // Full Adders
    full_adder FA0 (A[0], B_xor[0], mode, S[0], C1);
    full_adder FA1 (A[1], B_xor[1], C1, S[1], C2);
    full_adder FA2 (A[2], B_xor[2], C2, S[2], C3);
    full_adder FA3 (A[3], B_xor[3], C3, S[3], Cout);

endmodule

// Full Adder Module
module full_adder(
    input A, B, Cin,
    output Sum, Cout
);
    assign Sum = A ^ B ^ Cin;
    assign Cout = (A & B) | (B & Cin) | (A & Cin);
endmodule

// Testbench
module testbench;
    reg [3:0] A, B;
    reg mode;
    wire [3:0] S;
    wire Cout;

    adder_subtractor uut(A, B, mode, S, Cout);

    initial begin
	$dumpfile("add_sub.vcd");
        $dumpvars(0, testbench);

	$display("| Time |   A   |   B   |  Mode  | Output | CarryOut |");
        $monitor("|  %0t  |  %b |  %b |   %b    |   %b  |   %b    |", 
                  $time, A, B, mode, S, Cout);
        
        A = 4'b0101; B = 4'b0011; mode = 0; #10; // 5 + 3
        A = 4'b0110; B = 4'b0001; mode = 1; #10; // 6 - 1
        A = 4'b1000; B = 4'b0010; mode = 0; #10; // 8 + 2
        A = 4'b0111; B = 4'b0100; mode = 1; #10; // 7 - 4
        
        $finish;
    end
endmodule
