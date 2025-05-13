// Binary to Gray Code Converter
module binary_to_gray(input [3:0] binary, output [3:0] gray);
    assign gray[3] = binary[3];
    assign gray[2] = binary[3] ^ binary[2];
    assign gray[1] = binary[2] ^ binary[1];
    assign gray[0] = binary[1] ^ binary[0];
endmodule

// Testbench for Binary to Gray
module test_binary_to_gray;
    reg [3:0] binary;
    wire [3:0] gray;

    binary_to_gray b2g(binary, gray);

    initial begin
        $dumpfile("binary_to_gray.vcd");
        $dumpvars(0, test_binary_to_gray);

	$display("| Time |  Binary   |  Gray   |");
        $monitor("| %0t   |   %b    |   %b  |", $time, binary, gray);
        
        binary = 4'b0000; #10;
        binary = 4'b0001; #10;
        binary = 4'b0010; #10;
        binary = 4'b0011; #10;
        binary = 4'b0100; #10;
        binary = 4'b0101; #10;
        binary = 4'b0110; #10;
        binary = 4'b0111; #10;
        
        $finish;
    end
endmodule
