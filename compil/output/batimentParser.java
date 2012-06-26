// $ANTLR 3.4 C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g 2012-06-14 14:09:07

import java.util.LinkedList;


import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked"})
public class batimentParser extends Parser {
    public static final String[] tokenNames = new String[] {
        "<invalid>", "<EOR>", "<DOWN>", "<UP>", "ADJ", "CONST", "EXPONENT", "FLOAT", "ID", "INT", "WS", "'#'", "'$'", "'('", "')'", "','", "'->'", "'.'", "';'", "'='", "'=='", "'@'", "'^'", "'cluster('", "'cycle('", "'grammaire'", "'sequence('", "'{'", "'}'"
    };

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
    public static final int ADJ=4;
    public static final int CONST=5;
    public static final int EXPONENT=6;
    public static final int FLOAT=7;
    public static final int ID=8;
    public static final int INT=9;
    public static final int WS=10;

    // delegates
    public Parser[] getDelegates() {
        return new Parser[] {};
    }

    // delegators


    public batimentParser(TokenStream input) {
        this(input, new RecognizerSharedState());
    }
    public batimentParser(TokenStream input, RecognizerSharedState state) {
        super(input, state);
    }

    public String[] getTokenNames() { return batimentParser.tokenNames; }
    public String getGrammarFileName() { return "C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g"; }


    int n=0;
    int n2=0;


    // $ANTLR start "grammaire"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:12:1: grammaire : dinclude dnom= def_nom def_regles ;
    public final void grammaire() throws RecognitionException {
        String dnom =null;


        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:13:2: ( dinclude dnom= def_nom def_regles )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:13:4: dinclude dnom= def_nom def_regles
            {
            System.out.println("#include \"Parser.h\"");
            System.out.println("#include <vector>");
            System.out.println("#include <string>");
            System.out.println("#include \"regles/RegleStandard.h\"");
            System.out.println("#include \"regles/RegleSequence.h\"");
            System.out.println("#include \"regles/RegleCluster.h\"");
            System.out.println("#include \"regles/RegleCycle.h\"");
            System.out.println("#include \"condition/ConditionAdj.h\"");
            System.out.println("#include \"condition/ConditionEgal.h\"");
            System.out.println("#include \"regles/CalculAttributs.h\"");

            pushFollow(FOLLOW_dinclude_in_grammaire27);
            dinclude();

            state._fsp--;


            pushFollow(FOLLOW_def_nom_in_grammaire31);
            dnom=def_nom();

            state._fsp--;


            System.out.println("class Parser"+dnom+" : public Parser {");
            System.out.println("public:");
            	System.out.println("Parser"+dnom+"(){");

            pushFollow(FOLLOW_def_regles_in_grammaire36);
            def_regles();

            state._fsp--;



            	System.out.println("}};");
            	

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "grammaire"



    // $ANTLR start "dinclude"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:31:1: dinclude : ( '#' i= ID )* ;
    public final void dinclude() throws RecognitionException {
        Token i=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:32:2: ( ( '#' i= ID )* )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:32:4: ( '#' i= ID )*
            {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:32:4: ( '#' i= ID )*
            loop1:
            do {
                int alt1=2;
                int LA1_0 = input.LA(1);

                if ( (LA1_0==11) ) {
                    alt1=1;
                }


                switch (alt1) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:32:5: '#' i= ID
            	    {
            	    match(input,11,FOLLOW_11_in_dinclude48); 

            	    i=(Token)match(input,ID,FOLLOW_ID_in_dinclude52); 

            	    System.out.println("#include \""+(i!=null?i.getText():null)+".cpp\"");

            	    }
            	    break;

            	default :
            	    break loop1;
                }
            } while (true);


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "dinclude"



    // $ANTLR start "def_nom"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:34:1: def_nom returns [String nom] : 'grammaire' id= ID ;
    public final String def_nom() throws RecognitionException {
        String nom = null;


        Token id=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:34:29: ( 'grammaire' id= ID )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:34:31: 'grammaire' id= ID
            {
            match(input,25,FOLLOW_25_in_def_nom68); 

            id=(Token)match(input,ID,FOLLOW_ID_in_def_nom72); 

            nom= (id!=null?id.getText():null);

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return nom;
    }
    // $ANTLR end "def_nom"



    // $ANTLR start "def_regles"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:35:1: def_regles : ( regle_stand | regle_seq | regle_cycle | regle_cluster )* ;
    public final void def_regles() throws RecognitionException {
        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:36:2: ( ( regle_stand | regle_seq | regle_cycle | regle_cluster )* )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:36:4: ( regle_stand | regle_seq | regle_cycle | regle_cluster )*
            {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:36:4: ( regle_stand | regle_seq | regle_cycle | regle_cluster )*
            loop2:
            do {
                int alt2=5;
                int LA2_0 = input.LA(1);

                if ( (LA2_0==ID) ) {
                    int LA2_2 = input.LA(2);

                    if ( (LA2_2==16) ) {
                        switch ( input.LA(3) ) {
                        case 26:
                            {
                            alt2=2;
                            }
                            break;
                        case 24:
                            {
                            alt2=3;
                            }
                            break;
                        case 23:
                            {
                            alt2=4;
                            }
                            break;
                        case ID:
                            {
                            alt2=1;
                            }
                            break;

                        }

                    }


                }


                switch (alt2) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:36:5: regle_stand
            	    {
            	    pushFollow(FOLLOW_regle_stand_in_def_regles84);
            	    regle_stand();

            	    state._fsp--;


            	    }
            	    break;
            	case 2 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:36:17: regle_seq
            	    {
            	    pushFollow(FOLLOW_regle_seq_in_def_regles86);
            	    regle_seq();

            	    state._fsp--;


            	    }
            	    break;
            	case 3 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:36:27: regle_cycle
            	    {
            	    pushFollow(FOLLOW_regle_cycle_in_def_regles88);
            	    regle_cycle();

            	    state._fsp--;


            	    }
            	    break;
            	case 4 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:36:39: regle_cluster
            	    {
            	    pushFollow(FOLLOW_regle_cluster_in_def_regles90);
            	    regle_cluster();

            	    state._fsp--;


            	    }
            	    break;

            	default :
            	    break loop2;
                }
            } while (true);


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "def_regles"



    // $ANTLR start "regle_stand"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:38:2: regle_stand : i1= ID '->' i2= ID ( ',' i3= ID )* '{' ( liste_contraintes )? '}' '{' ( liste_calcul | '@' c= ID )? '}' ;
    public final void regle_stand() throws RecognitionException {
        Token i1=null;
        Token i2=null;
        Token i3=null;
        Token c=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:38:14: (i1= ID '->' i2= ID ( ',' i3= ID )* '{' ( liste_contraintes )? '}' '{' ( liste_calcul | '@' c= ID )? '}' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:38:16: i1= ID '->' i2= ID ( ',' i3= ID )* '{' ( liste_contraintes )? '}' '{' ( liste_calcul | '@' c= ID )? '}'
            {
            i1=(Token)match(input,ID,FOLLOW_ID_in_regle_stand104); 

            match(input,16,FOLLOW_16_in_regle_stand106); 


            	System.out.println("vector<string> v"+n+";");

            i2=(Token)match(input,ID,FOLLOW_ID_in_regle_stand115); 

            System.out.println("v"+n+".push_back(\""+(i2!=null?i2.getText():null)+"\");");

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:42:2: ( ',' i3= ID )*
            loop3:
            do {
                int alt3=2;
                int LA3_0 = input.LA(1);

                if ( (LA3_0==15) ) {
                    alt3=1;
                }


                switch (alt3) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:42:3: ',' i3= ID
            	    {
            	    match(input,15,FOLLOW_15_in_regle_stand121); 

            	    i3=(Token)match(input,ID,FOLLOW_ID_in_regle_stand125); 

            	    System.out.println("v"+n+".push_back(\""+(i3!=null?i3.getText():null)+"\");");

            	    }
            	    break;

            	default :
            	    break loop3;
                }
            } while (true);


            System.out.println("RegleStandard* r"+n+" = new RegleStandard(\""+(i1!=null?i1.getText():null)+"\",v"+n+");");System.out.println("ajouterRegle(r"+n+");");

            match(input,27,FOLLOW_27_in_regle_stand138); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:44:7: ( liste_contraintes )?
            int alt4=2;
            int LA4_0 = input.LA(1);

            if ( (LA4_0==ADJ||(LA4_0 >= 12 && LA4_0 <= 13)||LA4_0==21) ) {
                alt4=1;
            }
            switch (alt4) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:44:7: liste_contraintes
                    {
                    pushFollow(FOLLOW_liste_contraintes_in_regle_stand140);
                    liste_contraintes();

                    state._fsp--;


                    }
                    break;

            }


            match(input,28,FOLLOW_28_in_regle_stand142); 

            match(input,27,FOLLOW_27_in_regle_stand145); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:44:34: ( liste_calcul | '@' c= ID )?
            int alt5=3;
            int LA5_0 = input.LA(1);

            if ( (LA5_0==ID) ) {
                alt5=1;
            }
            else if ( (LA5_0==21) ) {
                alt5=2;
            }
            switch (alt5) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:44:35: liste_calcul
                    {
                    pushFollow(FOLLOW_liste_calcul_in_regle_stand148);
                    liste_calcul();

                    state._fsp--;


                    System.out.println("r"+n+"->calculAtt = new Calcul"+n+"();");

                    }
                    break;
                case 2 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:45:4: '@' c= ID
                    {
                    match(input,21,FOLLOW_21_in_regle_stand155); 

                    c=(Token)match(input,ID,FOLLOW_ID_in_regle_stand159); 

                    System.out.println("r"+n+"->calculAtt = new "+(c!=null?c.getText():null)+"();");

                    }
                    break;

            }


            match(input,28,FOLLOW_28_in_regle_stand165); 

            n++;n2=0;

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "regle_stand"



    // $ANTLR start "regle_seq"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:47:2: regle_seq : i1= ID '->' 'sequence(' i2= ID ',' '{' ( liste_contraintes )? '}' ')' '{' ( liste_calcul | '@' c= ID )? '}' ;
    public final void regle_seq() throws RecognitionException {
        Token i1=null;
        Token i2=null;
        Token c=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:47:12: (i1= ID '->' 'sequence(' i2= ID ',' '{' ( liste_contraintes )? '}' ')' '{' ( liste_calcul | '@' c= ID )? '}' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:47:14: i1= ID '->' 'sequence(' i2= ID ',' '{' ( liste_contraintes )? '}' ')' '{' ( liste_calcul | '@' c= ID )? '}'
            {
            i1=(Token)match(input,ID,FOLLOW_ID_in_regle_seq180); 

            match(input,16,FOLLOW_16_in_regle_seq182); 

            match(input,26,FOLLOW_26_in_regle_seq184); 

            i2=(Token)match(input,ID,FOLLOW_ID_in_regle_seq188); 

            System.out.println("RegleSequence* r"+n+" = new RegleSequence(\""+(i1!=null?i1.getText():null)+"\",\""+(i2!=null?i2.getText():null)+"\");");System.out.println("ajouterRegle(r"+n+");");

            match(input,15,FOLLOW_15_in_regle_seq193); 

            match(input,27,FOLLOW_27_in_regle_seq195); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:48:10: ( liste_contraintes )?
            int alt6=2;
            int LA6_0 = input.LA(1);

            if ( (LA6_0==ADJ||(LA6_0 >= 12 && LA6_0 <= 13)||LA6_0==21) ) {
                alt6=1;
            }
            switch (alt6) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:48:10: liste_contraintes
                    {
                    pushFollow(FOLLOW_liste_contraintes_in_regle_seq197);
                    liste_contraintes();

                    state._fsp--;


                    }
                    break;

            }


            match(input,28,FOLLOW_28_in_regle_seq199); 

            match(input,14,FOLLOW_14_in_regle_seq201); 

            match(input,27,FOLLOW_27_in_regle_seq203); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:48:40: ( liste_calcul | '@' c= ID )?
            int alt7=3;
            int LA7_0 = input.LA(1);

            if ( (LA7_0==ID) ) {
                alt7=1;
            }
            else if ( (LA7_0==21) ) {
                alt7=2;
            }
            switch (alt7) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:48:41: liste_calcul
                    {
                    pushFollow(FOLLOW_liste_calcul_in_regle_seq206);
                    liste_calcul();

                    state._fsp--;


                    System.out.println("r"+n+"->calculAtt = new Calcul"+n+"();");

                    }
                    break;
                case 2 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:49:3: '@' c= ID
                    {
                    match(input,21,FOLLOW_21_in_regle_seq212); 

                    c=(Token)match(input,ID,FOLLOW_ID_in_regle_seq216); 

                    System.out.println("r"+n+"->calculAtt = new "+(c!=null?c.getText():null)+"();");

                    }
                    break;

            }


            match(input,28,FOLLOW_28_in_regle_seq222); 

            n++;n2=0;

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "regle_seq"



    // $ANTLR start "regle_cycle"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:51:2: regle_cycle : i1= ID '->' 'cycle(' i2= ID ',' '{' ( liste_contraintes )? '}' ')' '{' ( liste_calcul | '@' c= ID )? '}' ;
    public final void regle_cycle() throws RecognitionException {
        Token i1=null;
        Token i2=null;
        Token c=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:51:14: (i1= ID '->' 'cycle(' i2= ID ',' '{' ( liste_contraintes )? '}' ')' '{' ( liste_calcul | '@' c= ID )? '}' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:51:16: i1= ID '->' 'cycle(' i2= ID ',' '{' ( liste_contraintes )? '}' ')' '{' ( liste_calcul | '@' c= ID )? '}'
            {
            i1=(Token)match(input,ID,FOLLOW_ID_in_regle_cycle237); 

            match(input,16,FOLLOW_16_in_regle_cycle239); 

            match(input,24,FOLLOW_24_in_regle_cycle241); 

            i2=(Token)match(input,ID,FOLLOW_ID_in_regle_cycle245); 

            System.out.println("RegleCycle* r"+n+" = new RegleCycle(\""+(i1!=null?i1.getText():null)+"\",\""+(i2!=null?i2.getText():null)+"\");");System.out.println("ajouterRegle(r"+n+");");

            match(input,15,FOLLOW_15_in_regle_cycle250); 

            match(input,27,FOLLOW_27_in_regle_cycle252); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:52:10: ( liste_contraintes )?
            int alt8=2;
            int LA8_0 = input.LA(1);

            if ( (LA8_0==ADJ||(LA8_0 >= 12 && LA8_0 <= 13)||LA8_0==21) ) {
                alt8=1;
            }
            switch (alt8) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:52:10: liste_contraintes
                    {
                    pushFollow(FOLLOW_liste_contraintes_in_regle_cycle254);
                    liste_contraintes();

                    state._fsp--;


                    }
                    break;

            }


            match(input,28,FOLLOW_28_in_regle_cycle256); 

            match(input,14,FOLLOW_14_in_regle_cycle258); 

            match(input,27,FOLLOW_27_in_regle_cycle260); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:52:40: ( liste_calcul | '@' c= ID )?
            int alt9=3;
            int LA9_0 = input.LA(1);

            if ( (LA9_0==ID) ) {
                alt9=1;
            }
            else if ( (LA9_0==21) ) {
                alt9=2;
            }
            switch (alt9) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:52:41: liste_calcul
                    {
                    pushFollow(FOLLOW_liste_calcul_in_regle_cycle263);
                    liste_calcul();

                    state._fsp--;


                    System.out.println("r"+n+"->calculAtt = new Calcul"+n+"();");

                    }
                    break;
                case 2 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:53:3: '@' c= ID
                    {
                    match(input,21,FOLLOW_21_in_regle_cycle269); 

                    c=(Token)match(input,ID,FOLLOW_ID_in_regle_cycle273); 

                    System.out.println("r"+n+"->calculAtt = new "+(c!=null?c.getText():null)+"();");

                    }
                    break;

            }


            match(input,28,FOLLOW_28_in_regle_cycle279); 

            n++;n2=0;

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "regle_cycle"



    // $ANTLR start "regle_cluster"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:55:2: regle_cluster : i1= ID '->' 'cluster(' i2= ID ',' '{' ( liste_contraintes )? '}' ')' '{' ( liste_calcul | '@' c= ID )? '}' ;
    public final void regle_cluster() throws RecognitionException {
        Token i1=null;
        Token i2=null;
        Token c=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:55:16: (i1= ID '->' 'cluster(' i2= ID ',' '{' ( liste_contraintes )? '}' ')' '{' ( liste_calcul | '@' c= ID )? '}' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:55:17: i1= ID '->' 'cluster(' i2= ID ',' '{' ( liste_contraintes )? '}' ')' '{' ( liste_calcul | '@' c= ID )? '}'
            {
            i1=(Token)match(input,ID,FOLLOW_ID_in_regle_cluster293); 

            match(input,16,FOLLOW_16_in_regle_cluster295); 

            match(input,23,FOLLOW_23_in_regle_cluster297); 

            i2=(Token)match(input,ID,FOLLOW_ID_in_regle_cluster301); 

            System.out.println("RegleCluster* r"+n+" = new RegleCluster(\""+(i1!=null?i1.getText():null)+"\",\""+(i2!=null?i2.getText():null)+"\");");System.out.println("ajouterRegle(r"+n+");");

            match(input,15,FOLLOW_15_in_regle_cluster306); 

            match(input,27,FOLLOW_27_in_regle_cluster308); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:56:10: ( liste_contraintes )?
            int alt10=2;
            int LA10_0 = input.LA(1);

            if ( (LA10_0==ADJ||(LA10_0 >= 12 && LA10_0 <= 13)||LA10_0==21) ) {
                alt10=1;
            }
            switch (alt10) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:56:10: liste_contraintes
                    {
                    pushFollow(FOLLOW_liste_contraintes_in_regle_cluster310);
                    liste_contraintes();

                    state._fsp--;


                    }
                    break;

            }


            match(input,28,FOLLOW_28_in_regle_cluster312); 

            match(input,14,FOLLOW_14_in_regle_cluster314); 

            match(input,27,FOLLOW_27_in_regle_cluster316); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:56:40: ( liste_calcul | '@' c= ID )?
            int alt11=3;
            int LA11_0 = input.LA(1);

            if ( (LA11_0==ID) ) {
                alt11=1;
            }
            else if ( (LA11_0==21) ) {
                alt11=2;
            }
            switch (alt11) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:56:41: liste_calcul
                    {
                    pushFollow(FOLLOW_liste_calcul_in_regle_cluster319);
                    liste_calcul();

                    state._fsp--;


                    System.out.println("r"+n+"->calculAtt = new Calcul"+n+"();");

                    }
                    break;
                case 2 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:57:3: '@' c= ID
                    {
                    match(input,21,FOLLOW_21_in_regle_cluster325); 

                    c=(Token)match(input,ID,FOLLOW_ID_in_regle_cluster329); 

                    System.out.println("r"+n+"->calculAtt = new "+(c!=null?c.getText():null)+"();");

                    }
                    break;

            }


            match(input,28,FOLLOW_28_in_regle_cluster335); 

            n++;n2=0;

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "regle_cluster"



    // $ANTLR start "liste_contraintes"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:59:1: liste_contraintes : contrainte ( '^' contrainte )* ;
    public final void liste_contraintes() throws RecognitionException {
        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:59:51: ( contrainte ( '^' contrainte )* )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:60:2: contrainte ( '^' contrainte )*
            {
            pushFollow(FOLLOW_contrainte_in_liste_contraintes347);
            contrainte();

            state._fsp--;


            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:60:13: ( '^' contrainte )*
            loop12:
            do {
                int alt12=2;
                int LA12_0 = input.LA(1);

                if ( (LA12_0==22) ) {
                    alt12=1;
                }


                switch (alt12) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:60:14: '^' contrainte
            	    {
            	    match(input,22,FOLLOW_22_in_liste_contraintes350); 

            	    pushFollow(FOLLOW_contrainte_in_liste_contraintes352);
            	    contrainte();

            	    state._fsp--;


            	    }
            	    break;

            	default :
            	    break loop12;
                }
            } while (true);


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "liste_contraintes"



    // $ANTLR start "liste_calcul"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:62:1: liste_calcul : ( expr_calcul ';' )+ ;
    public final void liste_calcul() throws RecognitionException {
        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:63:2: ( ( expr_calcul ';' )+ )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:64:2: ( expr_calcul ';' )+
            {
             System.out.println("class Calcul"+n+" : public CalculAttributs {");System.out.println("void calculAttrib(Noeud* nouveau){");

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:65:2: ( expr_calcul ';' )+
            int cnt13=0;
            loop13:
            do {
                int alt13=2;
                int LA13_0 = input.LA(1);

                if ( (LA13_0==ID) ) {
                    alt13=1;
                }


                switch (alt13) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:65:3: expr_calcul ';'
            	    {
            	    pushFollow(FOLLOW_expr_calcul_in_liste_calcul369);
            	    expr_calcul();

            	    state._fsp--;


            	    match(input,18,FOLLOW_18_in_liste_calcul371); 

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


            System.out.println("}};");

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "liste_calcul"



    // $ANTLR start "contrainte"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:67:2: contrainte : ( contrainte_egal | contrainte_adj | condition_unique | contrainte_generale | '(' contrainte ')' );
    public final void contrainte() throws RecognitionException {
        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:67:39: ( contrainte_egal | contrainte_adj | condition_unique | contrainte_generale | '(' contrainte ')' )
            int alt14=5;
            switch ( input.LA(1) ) {
            case 12:
                {
                int LA14_1 = input.LA(2);

                if ( (LA14_1==INT) ) {
                    int LA14_5 = input.LA(3);

                    if ( (LA14_5==17) ) {
                        int LA14_6 = input.LA(4);

                        if ( (LA14_6==ID) ) {
                            int LA14_7 = input.LA(5);

                            if ( (LA14_7==19) ) {
                                alt14=1;
                            }
                            else if ( (LA14_7==20) ) {
                                alt14=3;
                            }
                            else {
                                NoViableAltException nvae =
                                    new NoViableAltException("", 14, 7, input);

                                throw nvae;

                            }
                        }
                        else {
                            NoViableAltException nvae =
                                new NoViableAltException("", 14, 6, input);

                            throw nvae;

                        }
                    }
                    else {
                        NoViableAltException nvae =
                            new NoViableAltException("", 14, 5, input);

                        throw nvae;

                    }
                }
                else {
                    NoViableAltException nvae =
                        new NoViableAltException("", 14, 1, input);

                    throw nvae;

                }
                }
                break;
            case ADJ:
                {
                alt14=2;
                }
                break;
            case 21:
                {
                alt14=4;
                }
                break;
            case 13:
                {
                alt14=5;
                }
                break;
            default:
                NoViableAltException nvae =
                    new NoViableAltException("", 14, 0, input);

                throw nvae;

            }

            switch (alt14) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:68:2: contrainte_egal
                    {
                    pushFollow(FOLLOW_contrainte_egal_in_contrainte386);
                    contrainte_egal();

                    state._fsp--;


                    }
                    break;
                case 2 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:69:2: contrainte_adj
                    {
                    pushFollow(FOLLOW_contrainte_adj_in_contrainte390);
                    contrainte_adj();

                    state._fsp--;


                    }
                    break;
                case 3 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:70:2: condition_unique
                    {
                    pushFollow(FOLLOW_condition_unique_in_contrainte394);
                    condition_unique();

                    state._fsp--;


                    }
                    break;
                case 4 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:71:2: contrainte_generale
                    {
                    pushFollow(FOLLOW_contrainte_generale_in_contrainte398);
                    contrainte_generale();

                    state._fsp--;


                    }
                    break;
                case 5 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:72:2: '(' contrainte ')'
                    {
                    match(input,13,FOLLOW_13_in_contrainte402); 

                    pushFollow(FOLLOW_contrainte_in_contrainte404);
                    contrainte();

                    state._fsp--;


                    match(input,14,FOLLOW_14_in_contrainte405); 

                    }
                    break;

            }
        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "contrainte"



    // $ANTLR start "contrainte_egal"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:74:2: contrainte_egal : '$' i= INT '.' att_i= ID '=' '$' j= INT '.' att_j= ID ;
    public final void contrainte_egal() throws RecognitionException {
        Token i=null;
        Token att_i=null;
        Token j=null;
        Token att_j=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:74:18: ( '$' i= INT '.' att_i= ID '=' '$' j= INT '.' att_j= ID )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:74:20: '$' i= INT '.' att_i= ID '=' '$' j= INT '.' att_j= ID
            {
            match(input,12,FOLLOW_12_in_contrainte_egal415); 

            i=(Token)match(input,INT,FOLLOW_INT_in_contrainte_egal419); 

            match(input,17,FOLLOW_17_in_contrainte_egal421); 

            att_i=(Token)match(input,ID,FOLLOW_ID_in_contrainte_egal425); 

            match(input,19,FOLLOW_19_in_contrainte_egal427); 

            match(input,12,FOLLOW_12_in_contrainte_egal429); 

            j=(Token)match(input,INT,FOLLOW_INT_in_contrainte_egal433); 

            match(input,17,FOLLOW_17_in_contrainte_egal435); 

            att_j=(Token)match(input,ID,FOLLOW_ID_in_contrainte_egal439); 

            System.out.println("r"+n+"->condEgal.push_back(new ConditionEgal("+(i!=null?i.getText():null)+",\""+(att_i!=null?att_i.getText():null)+"\","+(j!=null?j.getText():null)+",\""+(att_j!=null?att_j.getText():null)+"\"));");

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "contrainte_egal"



    // $ANTLR start "contrainte_adj"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:75:2: contrainte_adj : ADJ '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')' ;
    public final void contrainte_adj() throws RecognitionException {
        Token i=null;
        Token att_i=null;
        Token j=null;
        Token att_j=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:75:17: ( ADJ '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:75:19: ADJ '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')'
            {
            match(input,ADJ,FOLLOW_ADJ_in_contrainte_adj449); 

            match(input,13,FOLLOW_13_in_contrainte_adj451); 

            match(input,12,FOLLOW_12_in_contrainte_adj453); 

            i=(Token)match(input,INT,FOLLOW_INT_in_contrainte_adj457); 

            match(input,17,FOLLOW_17_in_contrainte_adj459); 

            att_i=(Token)match(input,ID,FOLLOW_ID_in_contrainte_adj463); 

            match(input,15,FOLLOW_15_in_contrainte_adj465); 

            match(input,12,FOLLOW_12_in_contrainte_adj467); 

            j=(Token)match(input,INT,FOLLOW_INT_in_contrainte_adj471); 

            match(input,17,FOLLOW_17_in_contrainte_adj473); 

            att_j=(Token)match(input,ID,FOLLOW_ID_in_contrainte_adj477); 

            match(input,14,FOLLOW_14_in_contrainte_adj479); 

            System.out.println("r"+n+"->condAdj.push_back(new ConditionAdj("+(i!=null?i.getText():null)+",\""+(att_i!=null?att_i.getText():null)+"\","+(j!=null?j.getText():null)+",\""+(att_j!=null?att_j.getText():null)+"\"));");

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "contrainte_adj"



    // $ANTLR start "condition_unique"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:77:2: condition_unique : '$' i= INT '.' att_i= ID '==' val= CONST ;
    public final void condition_unique() throws RecognitionException {
        Token i=null;
        Token att_i=null;
        Token val=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:77:19: ( '$' i= INT '.' att_i= ID '==' val= CONST )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:77:21: '$' i= INT '.' att_i= ID '==' val= CONST
            {
            System.out.println("class ConditionUnique"+n+"_"+(++n2)+" : public ConditionUnique{");
            	System.out.println("bool estVerifiee(Noeud* n){return (bool)(");

            match(input,12,FOLLOW_12_in_condition_unique494); 

            i=(Token)match(input,INT,FOLLOW_INT_in_condition_unique498); 

            match(input,17,FOLLOW_17_in_condition_unique500); 

            att_i=(Token)match(input,ID,FOLLOW_ID_in_condition_unique504); 

            match(input,20,FOLLOW_20_in_condition_unique506); 

            val=(Token)match(input,CONST,FOLLOW_CONST_in_condition_unique510); 

            System.out.print("n->getAttribut(\""+(att_i!=null?att_i.getText():null)+"\"))=="+(val!=null?val.getText():null));
            		System.out.println(";}};");
            		System.out.println("ConditionUnique"+n+"_"+n2+"* c"+n+"_"+n2+" = new ConditionUnique"+n+"_"+n2+"(); c"+n+"_"+n2+"->indice = "+(i!=null?i.getText():null)+";");
            	System.out.println("r"+n+"->condUnique.push_back(c"+n+"_"+n2+");");

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "condition_unique"



    // $ANTLR start "contrainte_generale"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:85:2: contrainte_generale : '@' i= ID ;
    public final void contrainte_generale() throws RecognitionException {
        Token i=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:85:21: ( '@' i= ID )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:85:22: '@' i= ID
            {
            match(input,21,FOLLOW_21_in_contrainte_generale522); 

            i=(Token)match(input,ID,FOLLOW_ID_in_contrainte_generale526); 

            System.out.println("r"+n+"->condGen.push_back(new "+(i!=null?i.getText():null)+"());");

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "contrainte_generale"



    // $ANTLR start "expr_calcul"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:87:2: expr_calcul : att_i= ID '=' '$' j= INT '.' att_j= ID ;
    public final void expr_calcul() throws RecognitionException {
        Token att_i=null;
        Token j=null;
        Token att_j=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:87:14: (att_i= ID '=' '$' j= INT '.' att_j= ID )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:87:16: att_i= ID '=' '$' j= INT '.' att_j= ID
            {
            att_i=(Token)match(input,ID,FOLLOW_ID_in_expr_calcul539); 

            match(input,19,FOLLOW_19_in_expr_calcul541); 

            match(input,12,FOLLOW_12_in_expr_calcul543); 

            j=(Token)match(input,INT,FOLLOW_INT_in_expr_calcul547); 

            match(input,17,FOLLOW_17_in_expr_calcul549); 

            att_j=(Token)match(input,ID,FOLLOW_ID_in_expr_calcul553); 

            System.out.println("nouveau->setAttribut(\""+(att_i!=null?att_i.getText():null)+"\",nouveau->getEnfants()["+(j!=null?j.getText():null)+"]->getAttribut(\""+(att_j!=null?att_j.getText():null)+"\"));");

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "expr_calcul"

    // Delegated rules


 

    public static final BitSet FOLLOW_dinclude_in_grammaire27 = new BitSet(new long[]{0x0000000002000000L});
    public static final BitSet FOLLOW_def_nom_in_grammaire31 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_def_regles_in_grammaire36 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_11_in_dinclude48 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_dinclude52 = new BitSet(new long[]{0x0000000000000802L});
    public static final BitSet FOLLOW_25_in_def_nom68 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_def_nom72 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_regle_stand_in_def_regles84 = new BitSet(new long[]{0x0000000000000102L});
    public static final BitSet FOLLOW_regle_seq_in_def_regles86 = new BitSet(new long[]{0x0000000000000102L});
    public static final BitSet FOLLOW_regle_cycle_in_def_regles88 = new BitSet(new long[]{0x0000000000000102L});
    public static final BitSet FOLLOW_regle_cluster_in_def_regles90 = new BitSet(new long[]{0x0000000000000102L});
    public static final BitSet FOLLOW_ID_in_regle_stand104 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_16_in_regle_stand106 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_regle_stand115 = new BitSet(new long[]{0x0000000008008000L});
    public static final BitSet FOLLOW_15_in_regle_stand121 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_regle_stand125 = new BitSet(new long[]{0x0000000008008000L});
    public static final BitSet FOLLOW_27_in_regle_stand138 = new BitSet(new long[]{0x0000000010203010L});
    public static final BitSet FOLLOW_liste_contraintes_in_regle_stand140 = new BitSet(new long[]{0x0000000010000000L});
    public static final BitSet FOLLOW_28_in_regle_stand142 = new BitSet(new long[]{0x0000000008000000L});
    public static final BitSet FOLLOW_27_in_regle_stand145 = new BitSet(new long[]{0x0000000010200100L});
    public static final BitSet FOLLOW_liste_calcul_in_regle_stand148 = new BitSet(new long[]{0x0000000010000000L});
    public static final BitSet FOLLOW_21_in_regle_stand155 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_regle_stand159 = new BitSet(new long[]{0x0000000010000000L});
    public static final BitSet FOLLOW_28_in_regle_stand165 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ID_in_regle_seq180 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_16_in_regle_seq182 = new BitSet(new long[]{0x0000000004000000L});
    public static final BitSet FOLLOW_26_in_regle_seq184 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_regle_seq188 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_regle_seq193 = new BitSet(new long[]{0x0000000008000000L});
    public static final BitSet FOLLOW_27_in_regle_seq195 = new BitSet(new long[]{0x0000000010203010L});
    public static final BitSet FOLLOW_liste_contraintes_in_regle_seq197 = new BitSet(new long[]{0x0000000010000000L});
    public static final BitSet FOLLOW_28_in_regle_seq199 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_14_in_regle_seq201 = new BitSet(new long[]{0x0000000008000000L});
    public static final BitSet FOLLOW_27_in_regle_seq203 = new BitSet(new long[]{0x0000000010200100L});
    public static final BitSet FOLLOW_liste_calcul_in_regle_seq206 = new BitSet(new long[]{0x0000000010000000L});
    public static final BitSet FOLLOW_21_in_regle_seq212 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_regle_seq216 = new BitSet(new long[]{0x0000000010000000L});
    public static final BitSet FOLLOW_28_in_regle_seq222 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ID_in_regle_cycle237 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_16_in_regle_cycle239 = new BitSet(new long[]{0x0000000001000000L});
    public static final BitSet FOLLOW_24_in_regle_cycle241 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_regle_cycle245 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_regle_cycle250 = new BitSet(new long[]{0x0000000008000000L});
    public static final BitSet FOLLOW_27_in_regle_cycle252 = new BitSet(new long[]{0x0000000010203010L});
    public static final BitSet FOLLOW_liste_contraintes_in_regle_cycle254 = new BitSet(new long[]{0x0000000010000000L});
    public static final BitSet FOLLOW_28_in_regle_cycle256 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_14_in_regle_cycle258 = new BitSet(new long[]{0x0000000008000000L});
    public static final BitSet FOLLOW_27_in_regle_cycle260 = new BitSet(new long[]{0x0000000010200100L});
    public static final BitSet FOLLOW_liste_calcul_in_regle_cycle263 = new BitSet(new long[]{0x0000000010000000L});
    public static final BitSet FOLLOW_21_in_regle_cycle269 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_regle_cycle273 = new BitSet(new long[]{0x0000000010000000L});
    public static final BitSet FOLLOW_28_in_regle_cycle279 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ID_in_regle_cluster293 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_16_in_regle_cluster295 = new BitSet(new long[]{0x0000000000800000L});
    public static final BitSet FOLLOW_23_in_regle_cluster297 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_regle_cluster301 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_regle_cluster306 = new BitSet(new long[]{0x0000000008000000L});
    public static final BitSet FOLLOW_27_in_regle_cluster308 = new BitSet(new long[]{0x0000000010203010L});
    public static final BitSet FOLLOW_liste_contraintes_in_regle_cluster310 = new BitSet(new long[]{0x0000000010000000L});
    public static final BitSet FOLLOW_28_in_regle_cluster312 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_14_in_regle_cluster314 = new BitSet(new long[]{0x0000000008000000L});
    public static final BitSet FOLLOW_27_in_regle_cluster316 = new BitSet(new long[]{0x0000000010200100L});
    public static final BitSet FOLLOW_liste_calcul_in_regle_cluster319 = new BitSet(new long[]{0x0000000010000000L});
    public static final BitSet FOLLOW_21_in_regle_cluster325 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_regle_cluster329 = new BitSet(new long[]{0x0000000010000000L});
    public static final BitSet FOLLOW_28_in_regle_cluster335 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_contrainte_in_liste_contraintes347 = new BitSet(new long[]{0x0000000000400002L});
    public static final BitSet FOLLOW_22_in_liste_contraintes350 = new BitSet(new long[]{0x0000000000203010L});
    public static final BitSet FOLLOW_contrainte_in_liste_contraintes352 = new BitSet(new long[]{0x0000000000400002L});
    public static final BitSet FOLLOW_expr_calcul_in_liste_calcul369 = new BitSet(new long[]{0x0000000000040000L});
    public static final BitSet FOLLOW_18_in_liste_calcul371 = new BitSet(new long[]{0x0000000000000102L});
    public static final BitSet FOLLOW_contrainte_egal_in_contrainte386 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_contrainte_adj_in_contrainte390 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_condition_unique_in_contrainte394 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_contrainte_generale_in_contrainte398 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_13_in_contrainte402 = new BitSet(new long[]{0x0000000000203010L});
    public static final BitSet FOLLOW_contrainte_in_contrainte404 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_14_in_contrainte405 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_12_in_contrainte_egal415 = new BitSet(new long[]{0x0000000000000200L});
    public static final BitSet FOLLOW_INT_in_contrainte_egal419 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_egal421 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_contrainte_egal425 = new BitSet(new long[]{0x0000000000080000L});
    public static final BitSet FOLLOW_19_in_contrainte_egal427 = new BitSet(new long[]{0x0000000000001000L});
    public static final BitSet FOLLOW_12_in_contrainte_egal429 = new BitSet(new long[]{0x0000000000000200L});
    public static final BitSet FOLLOW_INT_in_contrainte_egal433 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_egal435 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_contrainte_egal439 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ADJ_in_contrainte_adj449 = new BitSet(new long[]{0x0000000000002000L});
    public static final BitSet FOLLOW_13_in_contrainte_adj451 = new BitSet(new long[]{0x0000000000001000L});
    public static final BitSet FOLLOW_12_in_contrainte_adj453 = new BitSet(new long[]{0x0000000000000200L});
    public static final BitSet FOLLOW_INT_in_contrainte_adj457 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_adj459 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_contrainte_adj463 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_contrainte_adj465 = new BitSet(new long[]{0x0000000000001000L});
    public static final BitSet FOLLOW_12_in_contrainte_adj467 = new BitSet(new long[]{0x0000000000000200L});
    public static final BitSet FOLLOW_INT_in_contrainte_adj471 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_adj473 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_contrainte_adj477 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_14_in_contrainte_adj479 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_12_in_condition_unique494 = new BitSet(new long[]{0x0000000000000200L});
    public static final BitSet FOLLOW_INT_in_condition_unique498 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_condition_unique500 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_condition_unique504 = new BitSet(new long[]{0x0000000000100000L});
    public static final BitSet FOLLOW_20_in_condition_unique506 = new BitSet(new long[]{0x0000000000000020L});
    public static final BitSet FOLLOW_CONST_in_condition_unique510 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_21_in_contrainte_generale522 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_contrainte_generale526 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ID_in_expr_calcul539 = new BitSet(new long[]{0x0000000000080000L});
    public static final BitSet FOLLOW_19_in_expr_calcul541 = new BitSet(new long[]{0x0000000000001000L});
    public static final BitSet FOLLOW_12_in_expr_calcul543 = new BitSet(new long[]{0x0000000000000200L});
    public static final BitSet FOLLOW_INT_in_expr_calcul547 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_expr_calcul549 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_expr_calcul553 = new BitSet(new long[]{0x0000000000000002L});

}