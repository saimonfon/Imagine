import java.io.*;
import org.antlr.runtime.*;

public class Test
{
public static void main(String[] args) throws Exception {
        batimentLexer lex = new batimentLexer(new ANTLRFileStream(args[0]));
        CommonTokenStream tokens = new CommonTokenStream(lex);
 
        batimentParser parser = new batimentParser(tokens);
        try {
            parser.grammaire();
        } catch (RecognitionException e)  {
            e.printStackTrace();
        }
    }
}