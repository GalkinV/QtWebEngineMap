new QWebChannel(qt.webChannelTransport,
   (channel) => {
   var server = channel.objects.server;
   window.server = server;


   server.wktToJS.connect((value) => {
                              drawWkt4326Polygon(value);
                        });

   //alert("Channel set");
  });
