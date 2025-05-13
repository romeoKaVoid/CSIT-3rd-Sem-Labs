// 4-bit Register using D Flip-Flops
module register_4bit (
    input clk, enable,  // Clock and enable signal
    input [3:0] D,      // 4-bit Data Input
    output reg [3:0] Q  // 4-bit Data Output
);
    always @(posedge clk) begin
        if (enable)
            Q <= D;  // Load input D into register on clock edge
    end
endmodule

// Testbench
module testbench;
    reg clk, enable;
    reg [3:0] D;
    wire [3:0] Q;
    
    register_4bit uut (clk, enable, D, Q);

    // Generate Clock Signal
    always #5 clk = ~clk;

    initial begin
	$dumpfile("reg.vcd");
        $dumpvars(0, testbench);

	$display("| Time |   D    | Enable |   Q    |");
        $monitor("|  %0t  |  %b  |   %b    |  %b  |", $time, D, enable, Q);
        
        clk = 0; enable = 1; D = 4'b1010; #10; // Load 1010
        D = 4'b1100; #10;  // Load 1100
        enable = 0; D = 4'b1111; #10; // Data should not change
        enable = 1; D = 4'b0001; #10; // Load 0001
        
        $finish;
    end
endmodule
