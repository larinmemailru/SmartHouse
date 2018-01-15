String webPage ="";

void page_begin() {
  webPage ="";
  webPage += "<html>";  
  webPage += "<head>";
  webPage += "  <meta charset='UTF-8'>";
}

void page_end() {
  webPage += "</html>";    
}

void page1() {
webPage += "  <title>Интерфейс WiFi модуля</title>";

webPage += "  <style>";
webPage += "  body { background: #f0f0f0; }";
webPage += "   @media screen and (max-width: 600px) {";
webPage += "     body { background: #fc0; }";
webPage += "   }";
webPage += "    .tabs {";
webPage += "      position: relative;   ";
webPage += "      min-height: 200px; ";
webPage += "      clear: both;";
webPage += "      margin: 1px 0;";
webPage += "    }";
webPage += "    .tab {";
webPage += "      float: left;";
webPage += "    }";
webPage += "    .tab label {";
webPage += "      background: #eee; ";
webPage += "      padding: 10px; ";
webPage += "      border: 1px solid #ccc; ";
webPage += "      margin-left: -1px; ";
webPage += "      position: relative;";
webPage += "      left: 1px; ";
webPage += "    }";
webPage += "    .tab [type=radio] {";
webPage += "      display: none;   ";
webPage += "    }";
webPage += "    .content {";
webPage += "      position: absolute;";
webPage += "      top: 50px;";
webPage += "      left: 0;";
webPage += "      background: white;";
webPage += "      right: 0;";
webPage += "      bottom: 0;";
webPage += "      padding: 20px;";
webPage += "      border: 1px solid #ccc; ";
    
webPage += "    overflow: hidden;";
webPage += "    }";
webPage += "    .content > * {";
webPage += "      opacity: 0;";
webPage += "      -webkit-transform: translate3d(0, 0, 0);";
webPage += "      -webkit-transform: translateX(-100%);";
webPage += "      -moz-transform:    translateX(-100%);";
webPage += "      -ms-transform:     translateX(-100%);";
webPage += "      -o-transform:      translateX(-100%);";
      
webPage += "      -webkit-transition: all 0.6s ease;";
webPage += "      -moz-transition:    all 0.6s ease;";
webPage += "      -ms-transition:     all 0.6s ease;";
webPage += "      -o-transition:      all 0.6s ease;";
webPage += "    }";
  
webPage += "    [type=radio]:checked ~ label {";
webPage += "      background: white;";
webPage += "      border-bottom: 1px solid white;";
webPage += "      z-index: 2;";
webPage += "    }";
  
webPage += "    [type=radio]:checked ~ label ~ .content {";
webPage += "      z-index: 1;";
webPage += "    }";
  
webPage += "  [type=radio]:checked ~ label ~ .content > * {";
webPage += "      opacity: 1;";
      
webPage += "      -webkit-transform: translateX(0);";
webPage += "      -moz-transform:    translateX(0);";
webPage += "      -ms-transform:     translateX(0);";
webPage += "      -o-transform:      translateX(0);";
webPage += "    }";
webPage += "  </style>";
webPage += "</head>";

webPage += "<body>";

webPage += "  <div id=\"page-wrap\">";
    
webPage += "    <div class=\"tabs\">";
        
webPage += "      <div class=\"tab\">";
webPage += "           <input type=\"radio\" id=\"tab-1\" name=\"tab-group-1\" checked>";
webPage += "           <label for=\"tab-1\">Температура</label>";
           
webPage += "           <div class=\"content\">";
webPage += "               <p>Датчик №1</p>";
webPage += "           </div> ";
webPage += "       </div>";
        
webPage += "       <div class=\"tab\">";
webPage += "           <input type=\"radio\" id=\"tab-2\" name=\"tab-group-1\">";
webPage += "           <label for=\"tab-2\">Ключи</label>";
           
webPage += "           <div class=\"content\">";
webPage += "               <p>Свет №1</p>";
               
webPage += "               <img src=\"http://placekitten.com/200/100\">";
webPage += "           </div>"; 
webPage += "       </div>";
        
webPage += "        <div class=\"tab\">";
webPage += "           <input type=\"radio\" id=\"tab-3\" name=\"tab-group-1\">";
webPage += "           <label for=\"tab-3\">Настройки</label>";
         
webPage += "           <div class=\"content\">";
webPage += "               <p>Параматры подключения к WiFi</p>";
               
webPage += "               <img src=\"http://placedog.com/200/100\">";
webPage += "           </div>"; 
webPage += "       </div>";
        
webPage += "    </div>";
  
webPage += "  </div>";
  
webPage += "</body>";
}

