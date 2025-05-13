`timescale 1ns / 1ps

module SimpleCPU;
    reg [7:0] regA, regB, result; // 8-bit registers
    reg [3:0] opcode;  // 4-bit opcode
    reg clk;

    // ALU Operations
    always @(posedge clk) begin
        case (opcode)
            4'b0000: result = regA + regB;  // ADD
            4'b0001: result = regA - regB;  // SUB
            4'b0010: result = regA & regB;  // AND
            4'b0011: result = regA | regB;  // OR
            4'b0100: result = regA ^ regB;  // XOR
            4'b0101: result = regA << 1;    // Left Shift
            4'b0110: result = regA >> 1;    // Right Shift
            default: result = 8'b00000000;  // Default case
        endcase
        $display("Opcode: %b | regA: %d, regB: %d, Result: %d", opcode, regA, regB, result);
    end

    initial begin
        $dumpfile("cpu_wave.vcd");  
        $dumpvars(0, SimpleCPU);

        clk = 0;

        // Test Cases
        regA = 8'd10; regB = 8'd5; opcode = 4'b0000; #10; // ADD
        regA = 8'd20; regB = 8'd7; opcode = 4'b0001; #10; // SUB
        regA = 8'b10101010; regB = 8'b11001100; opcode = 4'b0010; #10; // AND
        regA = 8'b10101010; regB = 8'b11001100; opcode = 4'b0011; #10; // OR
        regA = 8'd25; opcode = 4'b0101; #10; // Left Shift
        regA = 8'd50; opcode = 4'b0110; #10; // Right Shift

        $finish; // End simulation
    end

    always #5 clk = ~clk; // Generate Clock Signal
endmodule
