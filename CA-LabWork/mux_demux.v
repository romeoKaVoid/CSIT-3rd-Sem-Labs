module mux_demux;
    reg [3:0] I;  // 4 inputs for MUX
    reg [1:0] S;  // 2-bit select line
    reg IN;       // Input for DEMUX
    wire Y_mux;   // MUX output
    wire [3:0] Y_demux; // 4 outputs for DEMUX

    // 4:1 MUX
    assign Y_mux = (~S[1] & ~S[0] & I[0]) | 
                   (~S[1] & S[0] & I[1]) | 
                   (S[1] & ~S[0] & I[2]) | 
                   (S[1] & S[0] & I[3]);

    // 1:4 DEMUX
    assign Y_demux[0] = ~S[1] & ~S[0] & IN;
    assign Y_demux[1] = ~S[1] & S[0] & IN;
    assign Y_demux[2] = S[1] & ~S[0] & IN;
    assign Y_demux[3] = S[1] & S[0] & IN;

    initial begin
        $dumpfile("waveform.vcd");
        $dumpvars(0, mux_demux);

	$display("Time |  S    I    IN   ||  MUX Out: Y   || DEMUX Out: Y0  Y1  Y2  Y3 ");
        $monitor(" %0t  |  %b   %b   %b  ||           %b   ||             %b   %b   %b  %b",
                  $time, S, I, IN, Y_mux, Y_demux[0], Y_demux[1], Y_demux[2], Y_demux[3]);

        // Test cases
        I = 4'b1001; IN = 1; S = 2'b00; #10; // MUX selects I0, DEMUX outputs to Y0
        S = 2'b01; #10;                    // MUX selects I1, DEMUX outputs to Y1
        S = 2'b10; #10;                    // MUX selects I2, DEMUX outputs to Y2
        S = 2'b11; #10;                    // MUX selects I3, DEMUX outputs to Y3

        $finish;
    end
endmodule
