// Verilog Code for 8-bit Parity Generator and Checker
`timescale 1ns / 1ps

module parity_gen_checker;
    
    // Declare inputs and outputs
    reg [7:0] data;         // 8-bit input data
    wire parity_bit;        // Parity bit (Generated)
    wire error;             // Error detection signal
     
    // Generate Parity Bit (Even Parity)
    assign parity_bit = ^data; // XOR all bits to get even parity
    
    // Parity Checker
    assign error = ^{data, parity_bit}; // XOR data bits with parity bit to check
    
    // Simulation block
initial begin
    // Dump waveform file
    $dumpfile("waveform.vcd");
    $dumpvars(0, parity_gen_checker);

    // Test cases
 	$display("|   Time   |    Data     | Parity Bit | Error |");
    data = 8'b1111010; #10;
    $display("|   %0t  |  %b   |     %b      |   %b   |", $time, data, parity_bit, error);

    data = 8'b1111000; #10;
    $display("|   %0t  |  %b   |     %b      |   %b   |", $time, data, parity_bit, error);

    data = 8'b00000111; #10;
    $display("|   %0t  |  %b   |     %b      |   %b   |", $time, data, parity_bit, error);

    data = 8'b11001100; #10;
    $display("|   %0t  |  %b   |     %b      |   %b   |", $time, data, parity_bit, error);

    // End simulation
    #10 $finish;
end

endmodule
