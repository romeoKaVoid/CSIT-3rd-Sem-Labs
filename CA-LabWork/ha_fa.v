// Verilog Program for Half Adder and Full Adder
module half_adder (input A, B, output Sum, Carry);
    assign Sum = A ^ B;   // XOR for Sum
    assign Carry = A & B; // AND for Carry
endmodule

module full_adder (input A, B, Cin, output Sum, Carry);
    assign Sum = A ^ B ^ Cin; // XOR for Sum
    assign Carry = (A & B) | (Cin & (A ^ B)); // Carry-out
endmodule
module testbench;
    reg A, B, Cin;
    wire S_half, C_half, S_full, C_full;

    // Instantiate modules
    half_adder HA (A, B, S_half, C_half);
    full_adder FA (A, B, Cin, S_full, C_full);

    initial begin
        $dumpfile("waveform.vcd");
        $dumpvars(0, testbench);

        // Monitor to display values in terminal
	$display("Time |  A   |  B   | Cin  || Half Adder: Sum   Carry  || Full Adder: Sum   Carry");
        $monitor(" %0t |    %b  |   %b  |   %b  ||              %b     %b     ||               %b      %b",
                 $time, A, B, Cin, S_half, C_half, S_full, C_full);

        // Test cases
        A = 0; B = 0; Cin = 0; #10;
        A = 0; B = 0; Cin = 1; #10;
        A = 0; B = 1; Cin = 0; #10;
        A = 0; B = 1; Cin = 1; #10;
        A = 1; B = 0; Cin = 0; #10;
        A = 1; B = 0; Cin = 1; #10;
        A = 1; B = 1; Cin = 0; #10;
        A = 1; B = 1; Cin = 1; #10;

        $finish;
    end
endmodule
