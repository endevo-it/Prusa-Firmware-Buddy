# Resources for the PrusaLink web server

We have assortment of static "files" served by the PrusaLink web server. This
acts as a client-side application and offloads as much processing there.

The application comes from the <https://github.com/prusa3d/Prusa-Link-Web>.
Updating:

* Clone the above repository.
* Build the `mini` configuration.
* Replace the content of the `src_local` directory (keep the favicon).
* The build system will automatically gzip-compress them and embed the results
  in the output.
