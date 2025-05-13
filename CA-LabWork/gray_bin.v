// Gray to Binary Code Converter
module gray_to_binary(input [3:0] gray, output [3:0] binary);
    assign binary[3] = gray[3];
    assign binary[2] = gray[3] ^ gray[2];
    assign binary[1] = binary[2] ^ gray[1];
    assign binary[0] = binary[1] ^ gray[0];
endmodule

// Testbench for Gray to Binary
module test_gray_to_binary;
    reg [3:0] gray;
    wire [3:0] binary;

    gray_to_binary g2b(gray, binary);

    initial begin
        $dumpfile("gray_to_binary.vcd");
        $dumpvars(0, test_gray_to_binary);

	$display("| Time |  Gray   |  Binary |");
        $monitor("| %0t   |   %b  |   %b  |", $time, gray, binary);
        
        gray = 4'b0000; #10;
        gray = 4'b0001; #10;
        gray = 4'b0011; #10;
        gray = 4'b0010; #10;
        gray = 4'b0110; #10;
        gray = 4'b0111; #10;
        gray = 4'b0101; #10;
        gray = 4'b0100; #10;
        
        $finish;
    end
endmodule
