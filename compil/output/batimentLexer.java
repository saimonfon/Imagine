// $ANTLR 3.4 C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g 2012-06-28 16:30:58

import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked"})
public class batimentLexer extends Lexer {
    public static final int EOF=-1;
    public static final int T__11=11;
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
    public static final int EXPONENT=5;
    public static final int FLOAT=6;
    public static final int ID=7;
    public static final int INT=8;
    public static final int OP_COMP=9;
    public static final int WS=10;

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

    // $ANTLR start "T__11"
    public final void mT__11() throws RecognitionException {
        try {
            int _type = T__11;
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
    // $ANTLR end "T__11"

    // $ANTLR start "T__12"
    public final void mT__12() throws RecognitionException {
        try {
            int _type = T__12;
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
    // $ANTLR end "T__12"

    // $ANTLR start "T__13"
    public final void mT__13() throws RecognitionException {
        try {
            int _type = T__13;
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
    // $ANTLR end "T__13"

    // $ANTLR start "T__14"
    public final void mT__14() throws RecognitionException {
        try {
            int _type = T__14;
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
    // $ANTLR end "T__14"

    // $ANTLR start "T__15"
    public final void mT__15() throws RecognitionException {
        try {
            int _type = T__15;
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
    // $ANTLR end "T__15"

    // $ANTLR start "T__16"
    public final void mT__16() throws RecognitionException {
        try {
            int _type = T__16;
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
    // $ANTLR end "T__16"

    // $ANTLR start "T__17"
    public final void mT__17() throws RecognitionException {
        try {
            int _type = T__17;
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
    // $ANTLR end "T__17"

    // $ANTLR start "T__18"
    public final void mT__18() throws RecognitionException {
        try {
            int _type = T__18;
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
    // $ANTLR end "T__18"

    // $ANTLR start "T__19"
    public final void mT__19() throws RecognitionException {
        try {
            int _type = T__19;
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
    // $ANTLR end "T__19"

    // $ANTLR start "T__20"
    public final void mT__20() throws RecognitionException {
        try {
            int _type = T__20;
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
    // $ANTLR end "T__20"

    // $ANTLR start "T__21"
    public final void mT__21() throws RecognitionException {
        try {
            int _type = T__21;
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
    // $ANTLR end "T__21"

    // $ANTLR start "T__22"
    public final void mT__22() throws RecognitionException {
        try {
            int _type = T__22;
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
    // $ANTLR end "T__22"

    // $ANTLR start "T__23"
    public final void mT__23() throws RecognitionException {
        try {
            int _type = T__23;
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
    // $ANTLR end "T__23"

    // $ANTLR start "T__24"
    public final void mT__24() throws RecognitionException {
        try {
            int _type = T__24;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:15:7: ( 'false' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:15:9: 'false'
            {
            match("false"); 



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
    // $ANTLR end "T__25"

    // $ANTLR start "T__26"
    public final void mT__26() throws RecognitionException {
        try {
            int _type = T__26;
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
    // $ANTLR end "T__26"

    // $ANTLR start "T__27"
    public final void mT__27() throws RecognitionException {
        try {
            int _type = T__27;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:18:7: ( 'true' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:18:9: 'true'
            {
            match("true"); 



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
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:19:7: ( '{' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:19:9: '{'
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
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:20:7: ( '}' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:20:9: '}'
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

    // $ANTLR start "OP_COMP"
    public final void mOP_COMP() throws RecognitionException {
        try {
            int _type = OP_COMP;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:98:9: ( '==' | '>' | '<' | '>=' | '<=' | '!=' )
            int alt1=6;
            switch ( input.LA(1) ) {
            case '=':
                {
                alt1=1;
                }
                break;
            case '>':
                {
                int LA1_2 = input.LA(2);

                if ( (LA1_2=='=') ) {
                    alt1=4;
                }
                else {
                    alt1=2;
                }
                }
                break;
            case '<':
                {
                int LA1_3 = input.LA(2);

                if ( (LA1_3=='=') ) {
                    alt1=5;
                }
                else {
                    alt1=3;
                }
                }
                break;
            case '!':
                {
                alt1=6;
                }
                break;
            default:
                NoViableAltException nvae =
                    new NoViableAltException("", 1, 0, input);

                throw nvae;

            }

            switch (alt1) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:98:10: '=='
                    {
                    match("=="); 



                    }
                    break;
                case 2 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:98:15: '>'
                    {
                    match('>'); 

                    }
                    break;
                case 3 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:98:19: '<'
                    {
                    match('<'); 

                    }
                    break;
                case 4 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:98:23: '>='
                    {
                    match(">="); 



                    }
                    break;
                case 5 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:98:28: '<='
                    {
                    match("<="); 



                    }
                    break;
                case 6 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:98:33: '!='
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
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:99:6: ( 'adj' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:99:8: 'adj'
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
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:100:5: ( ( 'a' .. 'z' | 'A' .. 'Z' | '_' ) ( 'a' .. 'z' | 'A' .. 'Z' | '0' .. '9' | '_' )* )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:100:7: ( 'a' .. 'z' | 'A' .. 'Z' | '_' ) ( 'a' .. 'z' | 'A' .. 'Z' | '0' .. '9' | '_' )*
            {
            if ( (input.LA(1) >= 'A' && input.LA(1) <= 'Z')||input.LA(1)=='_'||(input.LA(1) >= 'a' && input.LA(1) <= 'z') ) {
                input.consume();
            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;
            }


            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:100:31: ( 'a' .. 'z' | 'A' .. 'Z' | '0' .. '9' | '_' )*
            loop2:
            do {
                int alt2=2;
                int LA2_0 = input.LA(1);

                if ( ((LA2_0 >= '0' && LA2_0 <= '9')||(LA2_0 >= 'A' && LA2_0 <= 'Z')||LA2_0=='_'||(LA2_0 >= 'a' && LA2_0 <= 'z')) ) {
                    alt2=1;
                }


                switch (alt2) {
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
            	    break loop2;
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
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:103:6: ( ( '0' .. '9' )+ )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:103:7: ( '0' .. '9' )+
            {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:103:7: ( '0' .. '9' )+
            int cnt3=0;
            loop3:
            do {
                int alt3=2;
                int LA3_0 = input.LA(1);

                if ( ((LA3_0 >= '0' && LA3_0 <= '9')) ) {
                    alt3=1;
                }


                switch (alt3) {
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
            	    if ( cnt3 >= 1 ) break loop3;
                        EarlyExitException eee =
                            new EarlyExitException(3, input);
                        throw eee;
                }
                cnt3++;
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
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:106:5: ( ( '0' .. '9' )+ '.' ( '0' .. '9' )* ( EXPONENT )? | '.' ( '0' .. '9' )+ ( EXPONENT )? | ( '0' .. '9' )+ EXPONENT )
            int alt10=3;
            alt10 = dfa10.predict(input);
            switch (alt10) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:106:9: ( '0' .. '9' )+ '.' ( '0' .. '9' )* ( EXPONENT )?
                    {
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:106:9: ( '0' .. '9' )+
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


                    match('.'); 

                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:106:25: ( '0' .. '9' )*
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
                    	    break loop5;
                        }
                    } while (true);


                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:106:37: ( EXPONENT )?
                    int alt6=2;
                    int LA6_0 = input.LA(1);

                    if ( (LA6_0=='E'||LA6_0=='e') ) {
                        alt6=1;
                    }
                    switch (alt6) {
                        case 1 :
                            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:106:37: EXPONENT
                            {
                            mEXPONENT(); 


                            }
                            break;

                    }


                    }
                    break;
                case 2 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:107:9: '.' ( '0' .. '9' )+ ( EXPONENT )?
                    {
                    match('.'); 

                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:107:13: ( '0' .. '9' )+
                    int cnt7=0;
                    loop7:
                    do {
                        int alt7=2;
                        int LA7_0 = input.LA(1);

                        if ( ((LA7_0 >= '0' && LA7_0 <= '9')) ) {
                            alt7=1;
                        }


                        switch (alt7) {
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
                    	    if ( cnt7 >= 1 ) break loop7;
                                EarlyExitException eee =
                                    new EarlyExitException(7, input);
                                throw eee;
                        }
                        cnt7++;
                    } while (true);


                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:107:25: ( EXPONENT )?
                    int alt8=2;
                    int LA8_0 = input.LA(1);

                    if ( (LA8_0=='E'||LA8_0=='e') ) {
                        alt8=1;
                    }
                    switch (alt8) {
                        case 1 :
                            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:107:25: EXPONENT
                            {
                            mEXPONENT(); 


                            }
                            break;

                    }


                    }
                    break;
                case 3 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:108:9: ( '0' .. '9' )+ EXPONENT
                    {
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:108:9: ( '0' .. '9' )+
                    int cnt9=0;
                    loop9:
                    do {
                        int alt9=2;
                        int LA9_0 = input.LA(1);

                        if ( ((LA9_0 >= '0' && LA9_0 <= '9')) ) {
                            alt9=1;
                        }


                        switch (alt9) {
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
                    	    if ( cnt9 >= 1 ) break loop9;
                                EarlyExitException eee =
                                    new EarlyExitException(9, input);
                                throw eee;
                        }
                        cnt9++;
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
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:111:5: ( ( ' ' | '\\t' | '\\r' | '\\n' ) )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:111:9: ( ' ' | '\\t' | '\\r' | '\\n' )
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
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:118:19: ( ( 'e' | 'E' ) ( '+' | '-' )? ( '0' .. '9' )+ )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:118:21: ( 'e' | 'E' ) ( '+' | '-' )? ( '0' .. '9' )+
            {
            if ( input.LA(1)=='E'||input.LA(1)=='e' ) {
                input.consume();
            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;
            }


            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:118:31: ( '+' | '-' )?
            int alt11=2;
            int LA11_0 = input.LA(1);

            if ( (LA11_0=='+'||LA11_0=='-') ) {
                alt11=1;
            }
            switch (alt11) {
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


            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:118:42: ( '0' .. '9' )+
            int cnt12=0;
            loop12:
            do {
                int alt12=2;
                int LA12_0 = input.LA(1);

                if ( ((LA12_0 >= '0' && LA12_0 <= '9')) ) {
                    alt12=1;
                }


                switch (alt12) {
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
            	    if ( cnt12 >= 1 ) break loop12;
                        EarlyExitException eee =
                            new EarlyExitException(12, input);
                        throw eee;
                }
                cnt12++;
            } while (true);


            }


        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "EXPONENT"

    public void mTokens() throws RecognitionException {
        // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:8: ( T__11 | T__12 | T__13 | T__14 | T__15 | T__16 | T__17 | T__18 | T__19 | T__20 | T__21 | T__22 | T__23 | T__24 | T__25 | T__26 | T__27 | T__28 | T__29 | OP_COMP | ADJ | ID | INT | FLOAT | WS )
        int alt13=25;
        alt13 = dfa13.predict(input);
        switch (alt13) {
            case 1 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:10: T__11
                {
                mT__11(); 


                }
                break;
            case 2 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:16: T__12
                {
                mT__12(); 


                }
                break;
            case 3 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:22: T__13
                {
                mT__13(); 


                }
                break;
            case 4 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:28: T__14
                {
                mT__14(); 


                }
                break;
            case 5 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:34: T__15
                {
                mT__15(); 


                }
                break;
            case 6 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:40: T__16
                {
                mT__16(); 


                }
                break;
            case 7 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:46: T__17
                {
                mT__17(); 


                }
                break;
            case 8 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:52: T__18
                {
                mT__18(); 


                }
                break;
            case 9 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:58: T__19
                {
                mT__19(); 


                }
                break;
            case 10 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:64: T__20
                {
                mT__20(); 


                }
                break;
            case 11 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:70: T__21
                {
                mT__21(); 


                }
                break;
            case 12 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:76: T__22
                {
                mT__22(); 


                }
                break;
            case 13 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:82: T__23
                {
                mT__23(); 


                }
                break;
            case 14 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:88: T__24
                {
                mT__24(); 


                }
                break;
            case 15 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:94: T__25
                {
                mT__25(); 


                }
                break;
            case 16 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:100: T__26
                {
                mT__26(); 


                }
                break;
            case 17 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:106: T__27
                {
                mT__27(); 


                }
                break;
            case 18 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:112: T__28
                {
                mT__28(); 


                }
                break;
            case 19 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:118: T__29
                {
                mT__29(); 


                }
                break;
            case 20 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:124: OP_COMP
                {
                mOP_COMP(); 


                }
                break;
            case 21 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:132: ADJ
                {
                mADJ(); 


                }
                break;
            case 22 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:136: ID
                {
                mID(); 


                }
                break;
            case 23 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:139: INT
                {
                mINT(); 


                }
                break;
            case 24 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:143: FLOAT
                {
                mFLOAT(); 


                }
                break;
            case 25 :
                // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:1:149: WS
                {
                mWS(); 


                }
                break;

        }

    }


    protected DFA10 dfa10 = new DFA10(this);
    protected DFA13 dfa13 = new DFA13(this);
    static final String DFA10_eotS =
        "\5\uffff";
    static final String DFA10_eofS =
        "\5\uffff";
    static final String DFA10_minS =
        "\2\56\3\uffff";
    static final String DFA10_maxS =
        "\1\71\1\145\3\uffff";
    static final String DFA10_acceptS =
        "\2\uffff\1\2\1\1\1\3";
    static final String DFA10_specialS =
        "\5\uffff}>";
    static final String[] DFA10_transitionS = {
            "\1\2\1\uffff\12\1",
            "\1\3\1\uffff\12\1\13\uffff\1\4\37\uffff\1\4",
            "",
            "",
            ""
    };

    static final short[] DFA10_eot = DFA.unpackEncodedString(DFA10_eotS);
    static final short[] DFA10_eof = DFA.unpackEncodedString(DFA10_eofS);
    static final char[] DFA10_min = DFA.unpackEncodedStringToUnsignedChars(DFA10_minS);
    static final char[] DFA10_max = DFA.unpackEncodedStringToUnsignedChars(DFA10_maxS);
    static final short[] DFA10_accept = DFA.unpackEncodedString(DFA10_acceptS);
    static final short[] DFA10_special = DFA.unpackEncodedString(DFA10_specialS);
    static final short[][] DFA10_transition;

    static {
        int numStates = DFA10_transitionS.length;
        DFA10_transition = new short[numStates][];
        for (int i=0; i<numStates; i++) {
            DFA10_transition[i] = DFA.unpackEncodedString(DFA10_transitionS[i]);
        }
    }

    class DFA10 extends DFA {

        public DFA10(BaseRecognizer recognizer) {
            this.recognizer = recognizer;
            this.decisionNumber = 10;
            this.eot = DFA10_eot;
            this.eof = DFA10_eof;
            this.min = DFA10_min;
            this.max = DFA10_max;
            this.accept = DFA10_accept;
            this.special = DFA10_special;
            this.transition = DFA10_transition;
        }
        public String getDescription() {
            return "105:1: FLOAT : ( ( '0' .. '9' )+ '.' ( '0' .. '9' )* ( EXPONENT )? | '.' ( '0' .. '9' )+ ( EXPONENT )? | ( '0' .. '9' )+ EXPONENT );";
        }
    }
    static final String DFA13_eotS =
        "\7\uffff\1\30\1\uffff\1\32\2\uffff\5\25\3\uffff\1\25\1\uffff\1\42"+
        "\4\uffff\7\25\1\uffff\6\25\1\60\5\25\1\66\1\uffff\1\25\1\70\1\71"+
        "\2\25\1\uffff\1\25\2\uffff\2\25\1\77\2\25\1\uffff\1\25\1\103\1\104"+
        "\2\uffff";
    static final String DFA13_eofS =
        "\105\uffff";
    static final String DFA13_minS =
        "\1\11\6\uffff\1\60\1\uffff\1\75\2\uffff\1\154\1\141\1\162\1\145"+
        "\1\162\3\uffff\1\144\1\uffff\1\56\4\uffff\1\165\1\143\1\154\1\141"+
        "\1\161\1\165\1\152\1\uffff\1\163\1\154\1\163\1\155\1\165\1\145\1"+
        "\60\1\164\2\145\1\155\1\145\1\60\1\uffff\1\145\2\60\1\141\1\156"+
        "\1\uffff\1\162\2\uffff\1\151\1\143\1\60\1\162\1\145\1\uffff\1\145"+
        "\2\60\2\uffff";
    static final String DFA13_maxS =
        "\1\175\6\uffff\1\71\1\uffff\1\75\2\uffff\1\171\1\141\1\162\1\145"+
        "\1\162\3\uffff\1\144\1\uffff\1\145\4\uffff\1\165\1\143\1\154\1\141"+
        "\1\161\1\165\1\152\1\uffff\1\163\1\154\1\163\1\155\1\165\1\145\1"+
        "\172\1\164\2\145\1\155\1\145\1\172\1\uffff\1\145\2\172\1\141\1\156"+
        "\1\uffff\1\162\2\uffff\1\151\1\143\1\172\1\162\1\145\1\uffff\1\145"+
        "\2\172\2\uffff";
    static final String DFA13_acceptS =
        "\1\uffff\1\1\1\2\1\3\1\4\1\5\1\6\1\uffff\1\10\1\uffff\1\12\1\13"+
        "\5\uffff\1\22\1\23\1\24\1\uffff\1\26\1\uffff\1\31\1\7\1\30\1\11"+
        "\7\uffff\1\27\15\uffff\1\25\5\uffff\1\21\1\uffff\1\15\1\16\5\uffff"+
        "\1\14\3\uffff\1\20\1\17";
    static final String DFA13_specialS =
        "\105\uffff}>";
    static final String[] DFA13_transitionS = {
            "\2\27\2\uffff\1\27\22\uffff\1\27\1\23\1\uffff\1\1\1\2\3\uffff"+
            "\1\3\1\4\2\uffff\1\5\1\6\1\7\1\uffff\12\26\1\uffff\1\10\1\23"+
            "\1\11\1\23\1\uffff\1\12\32\25\3\uffff\1\13\1\25\1\uffff\1\24"+
            "\1\25\1\14\2\25\1\15\1\16\13\25\1\17\1\20\6\25\1\21\1\uffff"+
            "\1\22",
            "",
            "",
            "",
            "",
            "",
            "",
            "\12\31",
            "",
            "\1\23",
            "",
            "",
            "\1\33\14\uffff\1\34",
            "\1\35",
            "\1\36",
            "\1\37",
            "\1\40",
            "",
            "",
            "",
            "\1\41",
            "",
            "\1\31\1\uffff\12\26\13\uffff\1\31\37\uffff\1\31",
            "",
            "",
            "",
            "",
            "\1\43",
            "\1\44",
            "\1\45",
            "\1\46",
            "\1\47",
            "\1\50",
            "\1\51",
            "",
            "\1\52",
            "\1\53",
            "\1\54",
            "\1\55",
            "\1\56",
            "\1\57",
            "\12\25\7\uffff\32\25\4\uffff\1\25\1\uffff\32\25",
            "\1\61",
            "\1\62",
            "\1\63",
            "\1\64",
            "\1\65",
            "\12\25\7\uffff\32\25\4\uffff\1\25\1\uffff\32\25",
            "",
            "\1\67",
            "\12\25\7\uffff\32\25\4\uffff\1\25\1\uffff\32\25",
            "\12\25\7\uffff\32\25\4\uffff\1\25\1\uffff\32\25",
            "\1\72",
            "\1\73",
            "",
            "\1\74",
            "",
            "",
            "\1\75",
            "\1\76",
            "\12\25\7\uffff\32\25\4\uffff\1\25\1\uffff\32\25",
            "\1\100",
            "\1\101",
            "",
            "\1\102",
            "\12\25\7\uffff\32\25\4\uffff\1\25\1\uffff\32\25",
            "\12\25\7\uffff\32\25\4\uffff\1\25\1\uffff\32\25",
            "",
            ""
    };

    static final short[] DFA13_eot = DFA.unpackEncodedString(DFA13_eotS);
    static final short[] DFA13_eof = DFA.unpackEncodedString(DFA13_eofS);
    static final char[] DFA13_min = DFA.unpackEncodedStringToUnsignedChars(DFA13_minS);
    static final char[] DFA13_max = DFA.unpackEncodedStringToUnsignedChars(DFA13_maxS);
    static final short[] DFA13_accept = DFA.unpackEncodedString(DFA13_acceptS);
    static final short[] DFA13_special = DFA.unpackEncodedString(DFA13_specialS);
    static final short[][] DFA13_transition;

    static {
        int numStates = DFA13_transitionS.length;
        DFA13_transition = new short[numStates][];
        for (int i=0; i<numStates; i++) {
            DFA13_transition[i] = DFA.unpackEncodedString(DFA13_transitionS[i]);
        }
    }

    class DFA13 extends DFA {

        public DFA13(BaseRecognizer recognizer) {
            this.recognizer = recognizer;
            this.decisionNumber = 13;
            this.eot = DFA13_eot;
            this.eof = DFA13_eof;
            this.min = DFA13_min;
            this.max = DFA13_max;
            this.accept = DFA13_accept;
            this.special = DFA13_special;
            this.transition = DFA13_transition;
        }
        public String getDescription() {
            return "1:1: Tokens : ( T__11 | T__12 | T__13 | T__14 | T__15 | T__16 | T__17 | T__18 | T__19 | T__20 | T__21 | T__22 | T__23 | T__24 | T__25 | T__26 | T__27 | T__28 | T__29 | OP_COMP | ADJ | ID | INT | FLOAT | WS );";
        }
    }
 

}