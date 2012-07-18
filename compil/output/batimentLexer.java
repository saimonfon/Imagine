// $ANTLR 3.4 C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g 2012-07-18 11:24:06

import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked"})
public class batimentLexer extends Lexer {
    public static final int EOF=-1;
    public static final int T__12=12;
    public static final int T__13=13;
    public static final int T__14=14;
    public static final int T__15=15;
    public static final int T__16=16;
    public static final int T__17=17;
    public static final int T__18=18;
    public static final int T__19=19;
    public static final int T__20=20;
    public static final int T__21=21;
    public static final int T__22=22;
    public static final int T__23=23;
    public static final int T__24=24;
    public static final int T__25=25;
    public static final int T__26=26;
    public static final int T__27=27;
    public static final int T__28=28;
    public static final int T__29=29;
    public static final int ADJ=4;
    public static final int BOOL=5;
    public static final int EXPONENT=6;
    public static final int FLOAT=7;
    public static final int ID=8;
    public static final int INT=9;
    public static final int OP_COMP=10;
    public static final int WS=11;

    // delegates
    // delegators
    public Lexer[] getDelegates() {
        return new Lexer[] {};
    }

    public batimentLexer() {} 
    public batimentLexer(CharStream input) {
        this(input, new RecognizerSharedState());
    }
    public batimentLexer(CharStream input, RecognizerSharedState state) {
        super(input,state);
    }
    public String getGrammarFileName() { return "C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g"; }

    // $ANTLR start "T__12"
    public final void mT__12() throws RecognitionException {
        try {
            int _type = T__12;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:2:7: ( '#' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:2:9: '#'
            {
            match('#'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__12"

    // $ANTLR start "T__13"
    public final void mT__13() throws RecognitionException {
        try {
            int _type = T__13;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:3:7: ( '$' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:3:9: '$'
            {
            match('$'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__13"

    // $ANTLR start "T__14"
    public final void mT__14() throws RecognitionException {
        try {
            int _type = T__14;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:4:7: ( '(' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:4:9: '('
            {
            match('('); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__14"

    // $ANTLR start "T__15"
    public final void mT__15() throws RecognitionException {
        try {
            int _type = T__15;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:5:7: ( ')' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:5:9: ')'
            {
            match(')'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__15"

    // $ANTLR start "T__16"
    public final void mT__16() throws RecognitionException {
        try {
            int _type = T__16;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:6:7: ( ',' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:6:9: ','
            {
            match(','); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__16"

    // $ANTLR start "T__17"
    public final void mT__17() throws RecognitionException {
        try {
            int _type = T__17;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:7:7: ( '->' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:7:9: '->'
            {
            match("->"); 



            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__17"

    // $ANTLR start "T__18"
    public final void mT__18() throws RecognitionException {
        try {
            int _type = T__18;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:8:7: ( '.' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:8:9: '.'
            {
            match('.'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__18"

    // $ANTLR start "T__19"
    public final void mT__19() throws RecognitionException {
        try {
            int _type = T__19;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:9:7: ( ';' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:9:9: ';'
            {
            match(';'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__19"

    // $ANTLR start "T__20"
    public final void mT__20() throws RecognitionException {
        try {
            int _type = T__20;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:10:7: ( '=' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:10:9: '='
            {
            match('='); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__20"

    // $ANTLR start "T__21"
    public final void mT__21() throws RecognitionException {
        try {
            int _type = T__21;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:11:7: ( '@' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:11:9: '@'
            {
            match('@'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__21"

    // $ANTLR start "T__22"
    public final void mT__22() throws RecognitionException {
        try {
            int _type = T__22;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:12:7: ( '^' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:12:9: '^'
            {
            match('^'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__22"

    // $ANTLR start "T__23"
    public final void mT__23() throws RecognitionException {
        try {
            int _type = T__23;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:13:7: ( 'cluster' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:13:9: 'cluster'
            {
            match("cluster"); 



            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__23"

    // $ANTLR start "T__24"
    public final void mT__24() throws RecognitionException {
        try {
            int _type = T__24;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:14:7: ( 'cycle' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:14:9: 'cycle'
            {
            match("cycle"); 



            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__24"

    // $ANTLR start "T__25"
    public final void mT__25() throws RecognitionException {
        try {
            int _type = T__25;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:15:7: ( 'ensemble' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:15:9: 'ensemble'
            {
            match("ensemble"); 



            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__25"

    // $ANTLR start "T__26"
    public final void mT__26() throws RecognitionException {
        try {
            int _type = T__26;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:16:7: ( 'grammaire' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:16:9: 'grammaire'
            {
            match("grammaire"); 



            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__26"

    // $ANTLR start "T__27"
    public final void mT__27() throws RecognitionException {
        try {
            int _type = T__27;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:17:7: ( 'sequence' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:17:9: 'sequence'
            {
            match("sequence"); 



            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__27"

    // $ANTLR start "T__28"
    public final void mT__28() throws RecognitionException {
        try {
            int _type = T__28;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:18:7: ( '{' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:18:9: '{'
            {
            match('{'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__28"

    // $ANTLR start "T__29"
    public final void mT__29() throws RecognitionException {
        try {
            int _type = T__29;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:19:7: ( '}' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:19:9: '}'
            {
            match('}'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__29"

    // $ANTLR start "BOOL"
    public final void mBOOL() throws RecognitionException {
        try {
            int _type = BOOL;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:102:7: ( 'true' | 'false' )
            int alt1=2;
            int LA1_0 = input.LA(1);

            if ( (LA1_0=='t') ) {
                alt1=1;
            }
            else if ( (LA1_0=='f') ) {
                alt1=2;
            }
            else {
                NoViableAltException nvae =
                    new NoViableAltException("", 1, 0, input);

                throw nvae;

            }
            switch (alt1) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:102:10: 'true'
                    {
                    match("true"); 



                    }
                    break;
                case 2 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:102:17: 'false'
                    {
                    match("false"); 



                    }
                    break;

            }
            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "BOOL"

    // $ANTLR start "OP_COMP"
    public final void mOP_COMP() throws RecognitionException {
        try {
            int _type = OP_COMP;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:103:9: ( '==' | '>' | '<' | '>=' | '<=' | '!=' )
            int alt2=6;
            switch ( input.LA(1) ) {
            case '=':
                {
                alt2=1;
                }
                break;
            case '>':
                {
                int LA2_2 = input.LA(2);

                if ( (LA2_2=='=') ) {
                    alt2=4;
                }
                else {
                    alt2=2;
                }
                }
                break;
            case '<':
                {
                int LA2_3 = input.LA(2);

                if ( (LA2_3=='=') ) {
                    alt2=5;
                }
                else {
                    alt2=3;
                }
                }
                break;
            case '!':
                {
                alt2=6;
                }
                break;
            default:
                NoViableAltException nvae =
                    new NoViableAltException("", 2, 0, input);

                throw nvae;

            }

            switch (alt2) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:103:10: '=='
                    {
                    match("=="); 



                    }
                    break;
                case 2 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:103:15: '>'
                    {
                    match('>'); 

                    }
                    break;
                case 3 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:103:19: '<'
                    {
                    match('<'); 

                    }
                    break;
                case 4 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:103:23: '>='
                    {
                    match(">="); 



                    }
                    break;
                case 5 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:103:28: '<='
                    {
                    match("<="); 



                    }
                    break;
                case 6 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:103:33: '!='
                    {
                    match("!="); 



                    }
                    break;

            }
            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "OP_COMP"

    // $ANTLR start "ADJ"
    public final void mADJ() throws RecognitionException {
        try {
            int _type = ADJ;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:104:6: ( 'adj' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:104:8: 'adj'
            {
            match("adj"); 



            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "ADJ"

    // $ANTLR start "ID"
    public final void mID() throws RecognitionException {
        try {
            int _type = ID;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:105:5: ( ( 'a' .. 'z' | 'A' .. 'Z' | '_' ) ( 'a' .. 'z' | 'A' .. 'Z' | '0' .. '9' | '_' )* )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:105:7: ( 'a' .. 'z' | 'A' .. 'Z' | '_' ) ( 'a' .. 'z' | 'A' .. 'Z' | '0' .. '9' | '_' )*
            {
            if ( (input.LA(1) >= 'A' && input.LA(1) <= 'Z')||input.LA(1)=='_'||(input.LA(1) >= 'a' && input.LA(1) <= 'z') ) {
                input.consume();
            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;
            }


            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:105:31: ( 'a' .. 'z' | 'A' .. 'Z' | '0' .. '9' | '_' )*
            loop3:
            do {
                int alt3=2;
                int LA3_0 = input.LA(1);

                if ( ((LA3_0 >= '0' && LA3_0 <= '9')||(LA3_0 >= 'A' && LA3_0 <= 'Z')||LA3_0=='_'||(LA3_0 >= 'a' && LA3_0 <= 'z')) ) {
                    alt3=1;
                }


                switch (alt3) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:
            	    {
            	    if ( (input.LA(1) >= '0' && input.LA(1) <= '9')||(input.LA(1) >= 'A' && input.LA(1) <= 'Z')||input.LA(1)=='_'||(input.LA(1) >= 'a' && input.LA(1) <= 'z') ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    break loop3;
                }
            } while (true);


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "ID"

    // $ANTLR start "INT"
    public final void mINT() throws RecognitionException {
        try {
            int _type = INT;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:108:6: ( ( '0' .. '9' )+ )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:108:7: ( '0' .. '9' )+
            {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:108:7: ( '0' .. '9' )+
            int cnt4=0;
            loop4:
            do {
                int alt4=2;
                int LA4_0 = input.LA(1);

                if ( ((LA4_0 >= '0' && LA4_0 <= '9')) ) {
                    alt4=1;
                }


                switch (alt4) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:
            	    {
            	    if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    if ( cnt4 >= 1 ) break loop4;
                        EarlyExitException eee =
                            new EarlyExitException(4, input);
                        throw eee;
                }
                cnt4++;
            } while (true);


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "INT"

    // $ANTLR start "FLOAT"
    public final void mFLOAT() throws RecognitionException {
        try {
            int _type = FLOAT;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:111:5: ( ( '0' .. '9' )+ '.' ( '0' .. '9' )* ( EXPONENT )? | '.' ( '0' .. '9' )+ ( EXPONENT )? | ( '0' .. '9' )+ EXPONENT )
            int alt11=3;
            alt11 = dfa11.predict(input);
            switch (alt11) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:111:9: ( '0' .. '9' )+ '.' ( '0' .. '9' )* ( EXPONENT )?
                    {
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:111:9: ( '0' .. '9' )+
                    int cnt5=0;
                    loop5:
                    do {
                        int alt5=2;
                        int LA5_0 = input.LA(1);

                        if ( ((LA5_0 >= '0' && LA5_0 <= '9')) ) {
                            alt5=1;
                        }


                        switch (alt5) {
                    	case 1 :
                    	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:
                    	    {
                    	    if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
                    	        input.consume();
                    	    }
                    	    else {
                    	        MismatchedSetException mse = new MismatchedSetException(null,input);
                    	        recover(mse);
                    	        throw mse;
                    	    }


                    	    }
                    	    break;

                    	default :
                    	    if ( cnt5 >= 1 ) break loop5;
                                EarlyExitException eee =
                                    new EarlyExitException(5, input);
                                throw eee;
                        }
                        cnt5++;
                    } while (true);


                    match('.'); 

                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:111:25: ( '0' .. '9' )*
                    loop6:
                    do {
                        int alt6=2;
                        int LA6_0 = input.LA(1);

                        if ( ((LA6_0 >= '0' && LA6_0 <= '9')) ) {
                            alt6=1;
                        }


                        switch (alt6) {
                    	case 1 :
                    	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:
                    	    {
                    	    if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
                    	        input.consume();
                    	    }
                    	    else {
                    	        MismatchedSetException mse = new MismatchedSetException(null,input);
                    	        recover(mse);
                    	        throw mse;
                    	    }


                    	    }
                    	    break;

                    	default :
                    	    break loop6;
                        }
                    } while (true);


                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:111:37: ( EXPONENT )?
                    int alt7=2;
                    int LA7_0 = input.LA(1);

                    if ( (LA7_0=='E'||LA7_0=='e') ) {
                        alt7=1;
                    }
                    switch (alt7) {
                        case 1 :
                            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:111:37: EXPONENT
                            {
                            mEXPONENT(); 


                            }
                            break;

                    }


                    }
                    break;
                case 2 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:112:9: '.' ( '0' .. '9' )+ ( EXPONENT )?
                    {
                    match('.'); 

                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:112:13: ( '0' .. '9' )+
                    int cnt8=0;
                    loop8:
                    do {
                        int alt8=2;
                        int LA8_0 = input.LA(1);

                        if ( ((LA8_0 >= '0' && LA8_0 <= '9')) ) {
                            alt8=1;
                        }


                        switch (alt8) {
                    	case 1 :
                    	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:
                    	    {
                    	    if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
                    	        input.consume();
                    	    }
                    	    else {
                    	        MismatchedSetException mse = new MismatchedSetException(null,input);
                    	        recover(mse);
                    	        throw mse;
                    	    }


                    	    }
                    	    break;

                    	default :
                    	    if ( cnt8 >= 1 ) break loop8;
                                EarlyExitException eee =
                                    new EarlyExitException(8, input);
                                throw eee;
                        }
                        cnt8++;
                    } while (true);


                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:112:25: ( EXPONENT )?
                    int alt9=2;
                    int LA9_0 = input.LA(1);

                    if ( (LA9_0=='E'||LA9_0=='e') ) {
                        alt9=1;
                    }
                    switch (alt9) {
                        case 1 :
                            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:112:25: EXPONENT
                            {
                            mEXPONENT(); 


                            }
                            break;

                    }


                    }
                    break;
                case 3 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:113:9: ( '0' .. '9' )+ EXPONENT
                    {
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:113:9: ( '0' .. '9' )+
                    int cnt10=0;
                    loop10:
                    do {
                        int alt10=2;
                        int LA10_0 = input.LA(1);

                        if ( ((LA10_0 >= '0' && LA10_0 <= '9')) ) {
                            alt10=1;
                        }


                        switch (alt10) {
                    	case 1 :
                    	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:
                    	    {
                    	    if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
                    	        input.consume();
                    	    }
                    	    else {
                    	        MismatchedSetException mse = new MismatchedSetException(null,input);
                    	        recover(mse);
                    	        throw mse;
                    	    }


                    	    }
                    	    break;

                    	default :
                    	    if ( cnt10 >= 1 ) break loop10;
                                EarlyExitException eee =
                                    new EarlyExitException(10, input);
                                throw eee;
                        }
                        cnt10++;
                    } while (true);


                    mEXPONENT(); 


                    }
                    break;

            }
            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "FLOAT"

    // $ANTLR start "WS"
    public final void mWS() throws RecognitionException {
        try {
            int _type = WS;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:116:5: ( ( ' ' | '\\t' | '\\r' | '\\n' ) )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:116:9: ( ' ' | '\\t' | '\\r' | '\\n' )
            {
            if ( (input.LA(1) >= '\t' && input.LA(1) <= '\n')||input.LA(1)=='\r'||input.LA(1)==' ' ) {
                input.consume();
            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;
            }


            _channel=HIDDEN;

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "WS"

    // $ANTLR start "EXPONENT"
    public final void mEXPONENT() throws RecognitionException {
        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:124:19: ( ( 'e' | 'E' ) ( '+' | '-' )? ( '0' .. '9' )+ )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:124:21: ( 'e' | 'E' ) ( '+' | '-' )? ( '0' .. '9' )+
            {
            if ( input.LA(1)=='E'||input.LA(1)=='e' ) {
                input.consume();
            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;
            }


            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:124:31: ( '+' | '-' )?
            int alt12=2;
            int LA12_0 = input.LA(1);

            if ( (LA12_0=='+'||LA12_0=='-') ) {
                alt12=1;
            }
            switch (alt12) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:
                    {
                    if ( input.LA(1)=='+'||input.LA(1)=='-' ) {
                        input.consume();
                    }
                    else {
                        MismatchedSetException mse = new MismatchedSetException(null,input);
                        recover(mse);
                        throw mse;
                    }


                    }
                    break;

            }


            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:124:42: ( '0' .. '9' )+
            int cnt13=0;
            loop13:
            do {
                int alt13=2;
                int LA13_0 = input.LA(1);

                if ( ((LA13_0 >= '0' && LA13_0 <= '9')) ) {
                    alt13=1;
                }


                switch (alt13) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:
            	    {
            	    if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    if ( cnt13 >= 1 ) break loop13;
                        EarlyExitException eee =
                            new EarlyExitException(13, input);
                        throw eee;
                }
                cnt13++;
            } while (true);


            }


        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "EXPONENT"

    public void mTokens() throws RecognitionException {
        // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:8: ( T__12 | T__13 | T__14 | T__15 | T__16 | T__17 | T__18 | T__19 | T__20 | T__21 | T__22 | T__23 | T__24 | T__25 | T__26 | T__27 | T__28 | T__29 | BOOL | OP_COMP | ADJ | ID | INT | FLOAT | WS )
        int alt14=25;
        alt14 = dfa14.predict(input);
        switch (alt14) {
            case 1 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:10: T__12
                {
                mT__12(); 


                }
                break;
            case 2 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:16: T__13
                {
                mT__13(); 


                }
                break;
            case 3 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:22: T__14
                {
                mT__14(); 


                }
                break;
            case 4 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:28: T__15
                {
                mT__15(); 


                }
                break;
            case 5 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:34: T__16
                {
                mT__16(); 


                }
                break;
            case 6 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:40: T__17
                {
                mT__17(); 


                }
                break;
            case 7 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:46: T__18
                {
                mT__18(); 


                }
                break;
            case 8 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:52: T__19
                {
                mT__19(); 


                }
                break;
            case 9 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:58: T__20
                {
                mT__20(); 


                }
                break;
            case 10 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:64: T__21
                {
                mT__21(); 


                }
                break;
            case 11 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:70: T__22
                {
                mT__22(); 


                }
                break;
            case 12 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:76: T__23
                {
                mT__23(); 


                }
                break;
            case 13 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:82: T__24
                {
                mT__24(); 


                }
                break;
            case 14 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:88: T__25
                {
                mT__25(); 


                }
                break;
            case 15 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:94: T__26
                {
                mT__26(); 


                }
                break;
            case 16 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:100: T__27
                {
                mT__27(); 


                }
                break;
            case 17 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:106: T__28
                {
                mT__28(); 


                }
                break;
            case 18 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:112: T__29
                {
                mT__29(); 


                }
                break;
            case 19 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:118: BOOL
                {
                mBOOL(); 


                }
                break;
            case 20 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:123: OP_COMP
                {
                mOP_COMP(); 


                }
                break;
            case 21 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:131: ADJ
                {
                mADJ(); 


                }
                break;
            case 22 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:135: ID
                {
                mID(); 


                }
                break;
            case 23 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:138: INT
                {
                mINT(); 


                }
                break;
            case 24 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:142: FLOAT
                {
                mFLOAT(); 


                }
                break;
            case 25 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:148: WS
                {
                mWS(); 


                }
                break;

        }

    }


    protected DFA11 dfa11 = new DFA11(this);
    protected DFA14 dfa14 = new DFA14(this);
    static final String DFA11_eotS =
        "\5\uffff";
    static final String DFA11_eofS =
        "\5\uffff";
    static final String DFA11_minS =
        "\2\56\3\uffff";
    static final String DFA11_maxS =
        "\1\71\1\145\3\uffff";
    static final String DFA11_acceptS =
        "\2\uffff\1\2\1\1\1\3";
    static final String DFA11_specialS =
        "\5\uffff}>";
    static final String[] DFA11_transitionS = {
            "\1\2\1\uffff\12\1",
            "\1\3\1\uffff\12\1\13\uffff\1\4\37\uffff\1\4",
            "",
            "",
            ""
    };

    static final short[] DFA11_eot = DFA.unpackEncodedString(DFA11_eotS);
    static final short[] DFA11_eof = DFA.unpackEncodedString(DFA11_eofS);
    static final char[] DFA11_min = DFA.unpackEncodedStringToUnsignedChars(DFA11_minS);
    static final char[] DFA11_max = DFA.unpackEncodedStringToUnsignedChars(DFA11_maxS);
    static final short[] DFA11_accept = DFA.unpackEncodedString(DFA11_acceptS);
    static final short[] DFA11_special = DFA.unpackEncodedString(DFA11_specialS);
    static final short[][] DFA11_transition;

    static {
        int numStates = DFA11_transitionS.length;
        DFA11_transition = new short[numStates][];
        for (int i=0; i<numStates; i++) {
            DFA11_transition[i] = DFA.unpackEncodedString(DFA11_transitionS[i]);
        }
    }

    class DFA11 extends DFA {

        public DFA11(BaseRecognizer recognizer) {
            this.recognizer = recognizer;
            this.decisionNumber = 11;
            this.eot = DFA11_eot;
            this.eof = DFA11_eof;
            this.min = DFA11_min;
            this.max = DFA11_max;
            this.accept = DFA11_accept;
            this.special = DFA11_special;
            this.transition = DFA11_transition;
        }
        public String getDescription() {
            return "110:1: FLOAT : ( ( '0' .. '9' )+ '.' ( '0' .. '9' )* ( EXPONENT )? | '.' ( '0' .. '9' )+ ( EXPONENT )? | ( '0' .. '9' )+ EXPONENT );";
        }
    }
    static final String DFA14_eotS =
        "\7\uffff\1\31\1\uffff\1\33\2\uffff\4\26\2\uffff\2\26\1\uffff\1\26"+
        "\1\uffff\1\44\4\uffff\10\26\1\uffff\7\26\1\64\5\26\1\72\1\26\1\uffff"+
        "\1\26\1\75\3\26\1\uffff\1\72\1\26\1\uffff\3\26\1\105\3\26\1\uffff"+
        "\1\111\1\26\1\113\1\uffff\1\114\2\uffff";
    static final String DFA14_eofS =
        "\115\uffff";
    static final String DFA14_minS =
        "\1\11\6\uffff\1\60\1\uffff\1\75\2\uffff\1\154\1\156\1\162\1\145"+
        "\2\uffff\1\162\1\141\1\uffff\1\144\1\uffff\1\56\4\uffff\1\165\1"+
        "\143\1\163\1\141\1\161\1\165\1\154\1\152\1\uffff\1\163\1\154\1\145"+
        "\1\155\1\165\1\145\1\163\1\60\1\164\1\145\2\155\1\145\1\60\1\145"+
        "\1\uffff\1\145\1\60\1\142\1\141\1\156\1\uffff\1\60\1\162\1\uffff"+
        "\1\154\1\151\1\143\1\60\1\145\1\162\1\145\1\uffff\1\60\1\145\1\60"+
        "\1\uffff\1\60\2\uffff";
    static final String DFA14_maxS =
        "\1\175\6\uffff\1\71\1\uffff\1\75\2\uffff\1\171\1\156\1\162\1\145"+
        "\2\uffff\1\162\1\141\1\uffff\1\144\1\uffff\1\145\4\uffff\1\165\1"+
        "\143\1\163\1\141\1\161\1\165\1\154\1\152\1\uffff\1\163\1\154\1\145"+
        "\1\155\1\165\1\145\1\163\1\172\1\164\1\145\2\155\1\145\1\172\1\145"+
        "\1\uffff\1\145\1\172\1\142\1\141\1\156\1\uffff\1\172\1\162\1\uffff"+
        "\1\154\1\151\1\143\1\172\1\145\1\162\1\145\1\uffff\1\172\1\145\1"+
        "\172\1\uffff\1\172\2\uffff";
    static final String DFA14_acceptS =
        "\1\uffff\1\1\1\2\1\3\1\4\1\5\1\6\1\uffff\1\10\1\uffff\1\12\1\13"+
        "\4\uffff\1\21\1\22\2\uffff\1\24\1\uffff\1\26\1\uffff\1\31\1\7\1"+
        "\30\1\11\10\uffff\1\27\17\uffff\1\25\5\uffff\1\23\2\uffff\1\15\7"+
        "\uffff\1\14\3\uffff\1\16\1\uffff\1\20\1\17";
    static final String DFA14_specialS =
        "\115\uffff}>";
    static final String[] DFA14_transitionS = {
            "\2\30\2\uffff\1\30\22\uffff\1\30\1\24\1\uffff\1\1\1\2\3\uffff"+
            "\1\3\1\4\2\uffff\1\5\1\6\1\7\1\uffff\12\27\1\uffff\1\10\1\24"+
            "\1\11\1\24\1\uffff\1\12\32\26\3\uffff\1\13\1\26\1\uffff\1\25"+
            "\1\26\1\14\1\26\1\15\1\23\1\16\13\26\1\17\1\22\6\26\1\20\1\uffff"+
            "\1\21",
            "",
            "",
            "",
            "",
            "",
            "",
            "\12\32",
            "",
            "\1\24",
            "",
            "",
            "\1\34\14\uffff\1\35",
            "\1\36",
            "\1\37",
            "\1\40",
            "",
            "",
            "\1\41",
            "\1\42",
            "",
            "\1\43",
            "",
            "\1\32\1\uffff\12\27\13\uffff\1\32\37\uffff\1\32",
            "",
            "",
            "",
            "",
            "\1\45",
            "\1\46",
            "\1\47",
            "\1\50",
            "\1\51",
            "\1\52",
            "\1\53",
            "\1\54",
            "",
            "\1\55",
            "\1\56",
            "\1\57",
            "\1\60",
            "\1\61",
            "\1\62",
            "\1\63",
            "\12\26\7\uffff\32\26\4\uffff\1\26\1\uffff\32\26",
            "\1\65",
            "\1\66",
            "\1\67",
            "\1\70",
            "\1\71",
            "\12\26\7\uffff\32\26\4\uffff\1\26\1\uffff\32\26",
            "\1\73",
            "",
            "\1\74",
            "\12\26\7\uffff\32\26\4\uffff\1\26\1\uffff\32\26",
            "\1\76",
            "\1\77",
            "\1\100",
            "",
            "\12\26\7\uffff\32\26\4\uffff\1\26\1\uffff\32\26",
            "\1\101",
            "",
            "\1\102",
            "\1\103",
            "\1\104",
            "\12\26\7\uffff\32\26\4\uffff\1\26\1\uffff\32\26",
            "\1\106",
            "\1\107",
            "\1\110",
            "",
            "\12\26\7\uffff\32\26\4\uffff\1\26\1\uffff\32\26",
            "\1\112",
            "\12\26\7\uffff\32\26\4\uffff\1\26\1\uffff\32\26",
            "",
            "\12\26\7\uffff\32\26\4\uffff\1\26\1\uffff\32\26",
            "",
            ""
    };

    static final short[] DFA14_eot = DFA.unpackEncodedString(DFA14_eotS);
    static final short[] DFA14_eof = DFA.unpackEncodedString(DFA14_eofS);
    static final char[] DFA14_min = DFA.unpackEncodedStringToUnsignedChars(DFA14_minS);
    static final char[] DFA14_max = DFA.unpackEncodedStringToUnsignedChars(DFA14_maxS);
    static final short[] DFA14_accept = DFA.unpackEncodedString(DFA14_acceptS);
    static final short[] DFA14_special = DFA.unpackEncodedString(DFA14_specialS);
    static final short[][] DFA14_transition;

    static {
        int numStates = DFA14_transitionS.length;
        DFA14_transition = new short[numStates][];
        for (int i=0; i<numStates; i++) {
            DFA14_transition[i] = DFA.unpackEncodedString(DFA14_transitionS[i]);
        }
    }

    class DFA14 extends DFA {

        public DFA14(BaseRecognizer recognizer) {
            this.recognizer = recognizer;
            this.decisionNumber = 14;
            this.eot = DFA14_eot;
            this.eof = DFA14_eof;
            this.min = DFA14_min;
            this.max = DFA14_max;
            this.accept = DFA14_accept;
            this.special = DFA14_special;
            this.transition = DFA14_transition;
        }
        public String getDescription() {
            return "1:1: Tokens : ( T__12 | T__13 | T__14 | T__15 | T__16 | T__17 | T__18 | T__19 | T__20 | T__21 | T__22 | T__23 | T__24 | T__25 | T__26 | T__27 | T__28 | T__29 | BOOL | OP_COMP | ADJ | ID | INT | FLOAT | WS );";
        }
    }
 

}