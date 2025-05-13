`timescale 1ns/1ps

module ALU;
    reg [3:0] A, B;
    reg [2:0] sel;
    wire [3:0] result;
    wire carry;

    // ALU Logic
    reg [4:0] temp_result;  // 5-bit to store carry
    always @(*) begin
        case(sel)
            3'b000: temp_result = A + B;      // Addition
            3'b001: temp_result = A - B;      // Subtraction
            3'b010: temp_result = A & B;      // Bitwise AND
            3'b011: temp_result = A | B;      // Bitwise OR
            3'b100: temp_result = A ^ B;      // Bitwise XOR
            3'b101: temp_result = ~A;         // NOT A
            3'b110: temp_result = (A > B) ? 4'b0001 : 4'b0000;  // A > B
            3'b111: temp_result = (A == B) ? 4'b0001 : 4'b0000; // A == B
            default: temp_result = 4'b0000;
        endcase
    end

    assign result = temp_result[3:0];  // Store lower 4 bits as result
    assign carry = temp_result[4];     // Store MSB as carry

    // Testbench
    initial begin
        $dumpfile("waveform.vcd");  // For GTKWave
        $dumpvars(0, ALU);

        // Test Cases
        A = 4'b1101; B = 4'b1011; sel = 3'b000; #10; // Addition
        $display("A=%b, B=%b, Sel=%b -> Result=%b, Carry=%b", A, B, sel, result, carry);

        A = 4'b1100; B = 4'b1010; sel = 3'b001; #10; // Subtraction
        $display("A=%b, B=%b, Sel=%b -> Result=%b, Carry=%b", A, B, sel, result, carry);

        A = 4'b1100; B = 4'b1010; sel = 3'b010; #10; // AND
        $display("A=%b, B=%b, Sel=%b -> Result=%b", A, B, sel, result);

        A = 4'b1100; B = 4'b1010; sel = 3'b011; #10; // OR
        $display("A=%b, B=%b, Sel=%b -> Result=%b", A, B, sel, result);

	A = 4'b1100; B = 4'b1010; sel = 3'b100; #10; // XOR
        $display("A=%b, B=%b, Sel=%b -> Result=%b", A, B, sel, result);

        A = 4'b1100; sel = 3'b101; #10; // NOT
        $display("A=%b,         Sel=%b -> Result=%b", A, sel, result);

	A = 4'b0011; B = 4'b1011; sel = 3'b110; #10; // greater Check
        $display("A=%b, B=%b, Sel=%b -> Result=%b", A, B, sel, result);

        A = 4'b1011; B = 4'b1011; sel = 3'b111; #10; // Equality Check
        $display("A=%b, B=%b, Sel=%b -> Result=%b", A, B, sel, result);

        $finish; // End simulation
    end
endmodule
