module Pipelined_CPU;
    reg [7:0] PC;   // Program Counter
    reg [7:0] instruction_memory [0:15]; // Instruction memory
    reg [7:0] register_file [0:7]; // Registers
    reg [7:0] data_memory [0:15]; // Data memory
    
    reg [7:0] FI_reg, DA_reg, FO_reg, EX_reg; // Pipeline registers

    initial begin
        PC = 0;
        
        // Initialize instructions (Simple ADD operations)
        instruction_memory[0] = 8'b00010010; // Example: ADD R1, R2
        instruction_memory[1] = 8'b00100011; // Example: ADD R2, R3
        instruction_memory[2] = 8'b01000001; // Example: ADD R4, R1
	instruction_memory[3] = 8'b01100100; // Example: ADD R6, R4
        
        // Initialize register values
        register_file[1] = 8'd5;
        register_file[2] = 8'd3;
        register_file[3] = 8'd7;
        register_file[4] = 8'd2;
	register_file[6] = 8'd9; // Initialize register R6
        
        // Initialize data memory (if needed)
        data_memory[2] = 8'd10;
        data_memory[3] = 8'd20;
        
        // Open dump file for GTKWave
        $dumpfile("pipeline.vcd");  
        $dumpvars(0, Pipelined_CPU);
        
        // Run pipeline simulation
        repeat (4) begin
            #5; // Delay for each pipeline stage
            execute_pipeline();
            PC = PC + 1; // Increment program counter
        end
        
        #10 $finish; // Stop simulation after 4 cycles
    end

    // Function to simulate pipeline behavior
    task execute_pipeline;
        begin
            // FI - Fetch Instruction
            FI_reg = instruction_memory[PC];

            // DA - Decode Address / Instruction
            DA_reg = FI_reg; // Simple forwarding (Normally decoding happens here)

            // FO - Fetch Operand
            FO_reg = register_file[DA_reg[3:0]]; // Fetching data from register based on instruction

            // EX - Execute
            EX_reg = FO_reg + register_file[DA_reg[7:4]]; // Example: ADD operation

            // Print Pipeline Stages in terminal
            $display("PC=%d | FI=%b | DA=%b | FO=%b | EX=%b", PC, FI_reg, DA_reg, FO_reg, EX_reg);
        end
    endtask
endmodule
