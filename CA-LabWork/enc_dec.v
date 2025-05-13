module encoder(input [3:0] in, output reg [1:0] out);
    always @(*) begin
        case (in)
            4'b0001: out = 2'b00;
            4'b0010: out = 2'b01;
            4'b0100: out = 2'b10;
            4'b1000: out = 2'b11;
            default: out = 2'bxx; // Undefined for multiple inputs
        endcase
    end
endmodule

module decoder(input [1:0] in, output reg [3:0] out);
    always @(*) begin
        case (in)
            2'b00: out = 4'b0001;
            2'b01: out = 4'b0010;
            2'b10: out = 4'b0100;
            2'b11: out = 4'b1000;
        endcase
    end
endmodule

module testbench;
    reg [3:0] enc_in;
    wire [1:0] enc_out;
    reg [1:0] dec_in;
    wire [3:0] dec_out;
    
    encoder enc(enc_in, enc_out);
    decoder dec(dec_in, dec_out);
    
    initial begin
	$dumpfile("encoder_decoder.vcd");
        $dumpvars(0, testbench);

	$display("| Time |Encoder Input|Encoder Output|Decoder Input|Decoder Output|");
        $monitor("|  %0t  |     %b    |      %b     |      %b      |      %b     |", 
                  $time, enc_in, enc_out, dec_in, dec_out);
                  
        enc_in = 4'b0001; dec_in = 2'b00; #10;
        enc_in = 4'b0010; dec_in = 2'b01; #10;
        enc_in = 4'b0100; dec_in = 2'b10; #10;
        enc_in = 4'b1000; dec_in = 2'b11; #10;
        
        $finish;
    end
endmodule
