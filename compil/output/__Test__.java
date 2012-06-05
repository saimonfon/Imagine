import java.io.*;
import org.antlr.runtime.*;
import org.antlr.runtime.debug.DebugEventSocketProxy;


public class __Test__ {

    public static void main(String args[]) throws Exception {
        batimentLexer lex = new batimentLexer(new ANTLRFileStream("C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\gramFile", "UTF8"));
        CommonTokenStream tokens = new CommonTokenStream(lex);

        batimentParser g = new batimentParser(tokens, 49100, null);
        try {
            g.grammaire();
        } catch (RecognitionException e) {
            e.printStackTrace();
        }
    }
}