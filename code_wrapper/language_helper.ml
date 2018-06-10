open Common

module C = Ast_c
module J = Ast_java



let conv_c_parsing_stat ps = 
  { 
    Statistics_parsing.correct = ps.Parsing_stat.correct;
    Statistics_parsing.bad = ps.Parsing_stat.bad;

    Statistics_parsing.filename = ps.Parsing_stat.filename;
    Statistics_parsing.have_timeout = ps.Parsing_stat.have_timeout;
    Statistics_parsing.commentized = ps.Parsing_stat.commentized;
  }

let conv_cplusplus_parsing_stat ps = 
  { 
    Statistics_parsing.correct = ps.Parsing_stat2.correct;
    Statistics_parsing.bad = ps.Parsing_stat2.bad;

    Statistics_parsing.filename = ps.Parsing_stat2.filename;
    Statistics_parsing.have_timeout = ps.Parsing_stat2.have_timeout;
    Statistics_parsing.commentized = ps.Parsing_stat2.commentized;
  }

let conv_java_parsing_stat ps = 
  { 
    Statistics_parsing.correct = ps.Parse_java.correct;
    Statistics_parsing.bad = ps.Parse_java.bad;
    
    Statistics_parsing.filename = "NOTDEFINE";
    Statistics_parsing.have_timeout = false;
    Statistics_parsing.commentized = 0;
  }
