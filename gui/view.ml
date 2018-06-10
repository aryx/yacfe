open Common

module G = Gui
module GKey = GdkKeysyms

open Model (* for field access *) 

(*****************************************************************************)
(* Prelude *)
(*****************************************************************************)

(*
 * Overall organisation:
 *  - menu
 *  - toolbar
 *  - mainview
 *    left         right
 *    ----         -----
 *    playlist     instrinc props
 *                 objects
 *                 source
 *  - statusbar 
 * 
 * Conventions:
 *  w = window, [hv]box = box, [hv]p, paned
 *  b = button, e = entry,  m = menu, mi = menuitem, r = range, fc = factory
 *  l = list, lbl = label
 * 
 * Model/View/Controller for global organization 
 * (model.ml, controller.ml, view.ml)
 * 
 * Model/View/Controller organization for many columns too. 
 *   - model = GTree columns+GTree store+fill function
 *   - view = GTree view+GTree view columns
 *   - controler = fill callback+change callback
 * So sometimes have a double model, the real data model (model.ml) and
 * then the model that is needed by Gtk to work with some TreeView.
 * 
 * 
 * When want add a feature:
 *  - add it to the model
 *  - add helpers and maybe fields in database/, comments/, etc
 *  - add gui code
 *)

(*****************************************************************************)
(* Globals, when some widgets need to access other widgets *)
(*****************************************************************************)
(* can also use the Controller module to achieve sometimes the same thing *)

let statusbar = 
  GMisc.statusbar () 

let ctx = 
  statusbar#new_context "main" 

let statusbar_addtext s = 
  ctx#push s +> ignore




let mapping_color = 
  ["Black";"DarkOrange";"DarkGreen";"DarkBlue";"DarkGray";"DarkYellow";] 

(*****************************************************************************)
(* Intermediate (big) widgets *)
(*****************************************************************************)

let mk_request model =
  let do_request request = 
    model.basic_query <- request;
    Controller.refresh_all model;
  in

  G.with_label "request:" 
    (G.mk (GEdit.entry ~text:"" ~max_length: 100) (fun e -> 
      e#connect#activate ~callback:(fun () -> 
        let request = e#text in
        pr ("Entry contents:" ^ request);
        do_request request
      );
    ))


(* @Obsolete *)
let mk_playlist_clist model =
  G.with_viewport (G.mk (GList.clist ~width:100 ~titles:["";"Playlist"]) 
  (fun l -> 
    [("1", "tag1");
     ("2", "tag2");
     ("3", "tag3");
     ("4", "tag4");
     ("5", "tag5");
    ] +> List.iter (fun (x1,x2) -> l#append [x1;x2] +> ignore);
    
    l#columns_autosize (); (* ??? *)
      
    ()
  ))


(* ------------------------------------------------------------------------- *)
(* Source code *)
(* ------------------------------------------------------------------------- *)
let mk_source_view ?height model = 
  G.with_viewport (G.mk  (GSourceView.source_view
                             ~auto_indent:true
                             ~insert_spaces_instead_of_tabs:true ~tabs_width:4
                             ~show_line_numbers:true
                             ~margin:80 ~show_margin:true
                             ~smart_home_end:true
                             ?height (*~width:650*)) 
  (fun srcview -> 

    let mngr = GSourceView.source_languages_manager () in
    let lang = mngr#get_language_from_mime_type "text/x-csrc" in
    srcview#source_buffer#set_language (Common.some lang);
    srcview#source_buffer#set_highlight true;
     

    let refresh_source id model = 
      match id with
      | None -> 
          srcview#source_buffer#set_text "no object selected yet"
      | Some o -> 
          ()
          (*
          let info = Model.comment_of_object o model in
           
          let filename = info.Comments.filename in
          let line = info.Comments.line in
                   
          let lines_comment = Common.nblines info.Comments.content in
          let text = Common.read_file filename in
           
          srcview#source_buffer#set_text text;

          let iter1 = 
            srcview#source_buffer#get_iter_at_char ~line:(line -1) 0 in
          let iter2 = 
            iter1#forward_lines lines_comment in

          let scroll_iter = iter2#forward_lines 2 in
          let mark = srcview#source_buffer#create_mark scroll_iter in
                   
          srcview#scroll_mark_onscreen (`MARK mark);
          (*srcview#scroll_to_iter ~use_align:true ~yalign:0.5 iter1;*)

          srcview#source_buffer#place_cursor iter1;

          srcview#source_buffer#select_range iter1 iter2;
          *)
    in
    Controller._refresh_source := refresh_source;
    refresh_source None model;
  ))



(*****************************************************************************)
(* Interactions *)
(*****************************************************************************)

(*****************************************************************************)
(* The main UI *)
(*****************************************************************************)

let mk_gui model path_xpm =
  let w = GWindow.window 
    ~title: "Yacfe GUI" 
    ~width:1024 ~height:700 (* 768, but Lin prefer 700 *)
    ~allow_shrink: true
    () 
  in
  let accel_group = GtkData.AccelGroup.create () in

  let quit () = 
    Controller.before_quit_all model;
    GMain.Main.quit ();
  in

  w#add_accel_group accel_group;
  
  w#add (G.mk (GPack.vbox) (fun vbox -> 
    (*-------------------------------------------------------------------*)
    (* Menu *)
    (*-------------------------------------------------------------------*)
    vbox#pack (G.mk (GMenu.menu_bar) (fun m -> 
      
      let factory = new GMenu.factory m in

      factory#add_submenu "_File" +> (fun menu -> 
        let fc = new GMenu.factory menu ~accel_group in
        fc#add_item "_Open file" ~key:GKey._O ~callback:(fun () -> 
          pr2 "OPEN";
        );
        fc#add_separator ();
        fc#add_item "_Quit" ~key:GKey._Q ~callback:quit;
      );

      factory#add_submenu "_Edit" +> (fun menu -> 
        GToolbox.build_menu menu ~entries:[
          `S;
        ];
      );

      factory#add_submenu "_View" +> (fun menu -> 
        GToolbox.build_menu menu ~entries:[
        ];
      );

      factory#add_submenu "_Statistics" +> (fun menu -> 
        GToolbox.build_menu menu ~entries:[
          `S;
        ]
      );


      factory#add_submenu "_Help" +> (fun menu -> 
        let fc = new GMenu.factory menu ~accel_group in
        fc#add_item "_Help on Yacfe" ~key:GKey._H ~callback:(fun () -> 
            G.dialog_text "Read\nthe\nsource\n\ndude" "Help"
        );
        fc#add_separator ();
        fc#add_item "About" ~callback:(fun () -> 
            G.dialog_text "Brought to you by padator\nwith love" "About"
        );
      );
    ));
    
    (*-------------------------------------------------------------------*)
    (* toolbar *)
    (*-------------------------------------------------------------------*)
    vbox#pack (G.mk (GButton.toolbar) (fun tb ->

      tb#insert_widget (G.mk (GButton.button ~stock:`OPEN) (fun b -> 
        b#connect#clicked ~callback:(fun () -> 
          pr2 "OPEN";
        );
      ));
      tb#insert_widget (G.mk (GButton.button ~stock:`SAVE) (fun b -> 
        b#connect#clicked ~callback:(fun () -> 
          pr2 "SAVE";
        );
      ));

      tb#insert_space ();
      tb#insert_button ~text:"SAVE THIS" ~callback:(fun () -> 
        pr2 "SAVE THIS";
      ) ();
      tb#insert_space ();
      
      (*---------------------------------------------------------------*)
      (* request and pwd *)
      (*---------------------------------------------------------------*)
      tb#insert_widget (mk_request model);
      tb#insert_space ();
    ));


    (*-------------------------------------------------------------------*)
    (* main view *)
    (*-------------------------------------------------------------------*)
    vbox#pack ~expand:true ~fill:true (G.mk (GPack.paned `HORIZONTAL)(fun hp ->

      (*---------------------------------------------------------------*)
      (* Playlist *)
      (*---------------------------------------------------------------*)
      (* hp#add1 (mk_playlist_tree model); *)

      (*---------------------------------------------------------------*)
      (* Other *)
      (*---------------------------------------------------------------*)
      hp#add2  (G.mk (GPack.paned `VERTICAL) (fun vp1 -> 
       vp1#add1  (G.mk (GPack.paned `VERTICAL) (fun vp1_1 -> 

         (*----------------------------------------------------*)
         (* Selection Columns *)
         (*----------------------------------------------------*)
         vp1_1#add1
          (G.mk (GPack.hbox ~height:350 ~border_width:4 ~spacing:1) (fun hbox -> 
           (* hbox#pack ~fill:true ~expand:true
             (mk_generic_column model);
           *)

            ()
           (*
           hbox#pack 
             (mk_column ~width:250 model
                 "place:" (model.col1_name, model.col1));
           hbox#pack 
             (mk_column ~width:300 model
                 "dir1:"
                 (model.col2_name, model.col2));
           hbox#pack 
             (mk_column ~width:300 model
                 "time_relative_around:"
                 (model.col3_name, model.col3));
           hbox#pack 
             (mk_column ~width:300 model
                 "dir1:"
                 (model.col4_name, model.col4));
           *)
         ));
         (*----------------------------------------------------*)
         (* Objects *)
         (*----------------------------------------------------*)
         (* vp1_1#add2 (mk_objects ~height:150 model); *)
         
       ));
        (*----------------------------------------------------*)
        (* The source file *)
        (*----------------------------------------------------*)
        vp1#add2 (mk_source_view ~height:200 model);

      ));

      hp#set_position 240;
    ));


    (*-------------------------------------------------------------------*)
    (* status bar *)
    (*-------------------------------------------------------------------*)
    (* the statusbar widget is defined in beginning of this file because *)
    vbox#pack (*~from: `END*) statusbar#coerce;
      
  ));

  (*-------------------------------------------------------------------*)
  (* End *)
  (*-------------------------------------------------------------------*)
  Controller._before_quit_all_func +> 
    Common.push2 Model.close_model;

  GtkSignal.user_handler := (fun exn -> 
    pr2 "fucking callback";
    raise exn
  );

  w#event#connect#key_press ~callback:(fun ev -> 
    let k = GdkEvent.Key.keyval ev in
    (match k with
(* pb intercept when enter stuff in object views
    | _ when k = Char.code 'q' -> 
        quit();
        true   
    | _ when k = Char.code 'n' -> 
        tag_expl_misc_current_object_and_go_next model;
        true
*)
    | _ -> false
    )
  );

  w#event#connect#delete    ~callback:(fun _  -> quit(); true);
  w#connect#destroy         ~callback:(fun () -> quit(); );
  w#show ();
  GMain.Main.main ();
  ()
