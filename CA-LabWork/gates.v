`timescale 1ns / 1ps

module Basic_Gates;
    // Inputs
    reg A, B;
    
    // Outputs
    wire AND_OUT, OR_OUT, NOT_A, XOR_OUT, NAND_OUT, NOR_OUT, XNOR_OUT;

    // Assign operations
    assign AND_OUT = A & B;
    assign OR_OUT = A | B;
    assign NOT_A = ~A;
    assign XOR_OUT = A ^ B;
    assign NAND_OUT = ~(A & B);
    assign NOR_OUT = ~(A | B);
    assign XNOR_OUT = ~(A ^ B);
    
    initial begin
        // Dump waveform file for GTKWave
        $dumpfile("waveform.vcd");
        $dumpvars(0, Basic_Gates);

        // Test cases
        A = 0; B = 0; #10;
        A = 0; B = 1; #10;
        A = 1; B = 0; #10;
        A = 1; B = 1; #10;

        // End simulation
        $finish;
    end
    
    initial begin
        $monitor("Time=%0t | A=%b  B=%b  | AND=%b  OR=%b  NOT_A=%b  XOR=%b  NAND=%b  NOR=%b  XNOR=%b", 
         $time, A, B, AND_OUT, OR_OUT, NOT_A, XOR_OUT, NAND_OUT, NOR_OUT, XNOR_OUT);

    end
endmodule
