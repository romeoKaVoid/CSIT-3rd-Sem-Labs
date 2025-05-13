// Verilog Module to Demonstrate Syntax, Data Types, and Operators
module basic_operations;
    // Declare variables
    reg [3:0] a, b;  // 4-bit registers
    wire [4:0] sum, diff, and_op, or_op, xor_op;
    wire greater, equal, less;
    
    // Assign operations
    assign sum = a + b;  // Addition
    assign diff = a - b; // Subtraction
    assign and_op = a & b; // Bitwise AND
    assign or_op = a | b;  // Bitwise OR
    assign xor_op = a ^ b; // Bitwise XOR

    // Relational operations
    assign greater = (a > b);
    assign equal = (a == b);
    assign less = (a < b);
    
    // Initial block for simulation
    initial begin
        // Assign values
        a = 4'b1101; // Binary 1101 (13 in decimal)
        b = 4'b0111; // Binary 0111 (7 in decimal)
        
	$dumpfile("waveform.vcd");  // Creates VCD file
	$dumpvars(0, basic_operations); // Dumps all signals of the module
	
	#10;
        // Display results
        #1; // Small delay for proper output
	$display("Basic Syntax and Operators in Verilog");
        $display("A = %b, B = %b", a, b);
        $display("Sum = %b, Difference = %b", sum, diff);
        $display("AND = %b, OR = %b, XOR = %b", and_op, or_op, xor_op);
        $display("Greater: %b, Equal: %b, Less: %b", greater, equal, less);
        
        // End simulation
        $finish;
    end
endmodule
