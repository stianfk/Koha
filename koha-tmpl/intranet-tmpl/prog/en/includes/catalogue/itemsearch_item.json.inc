[%- USE Branches -%]
[%- USE Koha -%]
[% USE AuthorisedValues %]
[%- biblio = item.biblio -%]
[%- biblioitem = item.biblioitem -%]
[
  "[% FILTER escape_quotes = replace('"', '\"') ~%]
    <a href="/cgi-bin/koha/catalogue/detail.pl?biblionumber=[% biblio.biblionumber %]" title="Go to record detail page">[% biblio.title |html %]</a>[% IF ( Koha.Preference( 'marcflavour' ) == 'UNIMARC' && biblio.author ) %] by[% END %] [% biblio.author |html %]
  [%~ END %]",
  "[% (biblioitem.publicationyear || biblio.copyrightdate) |html %]",
  "[% biblioitem.publishercode |html %]",
  "[% AuthorisedValues.GetByCode( 'CCODE', item.ccode ) %]",
  "[% FILTER escape_quotes ~%]
    <a href="/cgi-bin/koha/catalogue/moredetail.pl?biblionumber=[% biblio.biblionumber %]#item[% item.itemnumber %]" title="Go to item details">[% item.barcode |html %]</a>
  [%~ END %]",
  "[% item.itemcallnumber |html %]",
  "[% Branches.GetName(item.homebranch) |html %]",
  "[% Branches.GetName(item.holdingbranch) |html %]",
  "[% item.location |html %]",
  "[% item.stocknumber |html %]",
  "[% item.status |html %]",
  "[% (item.issues || 0) |html %]",
  "[% FILTER escape_quotes ~%]
    <div class="btn-group dropup"><button type="button" class="btn btn-xs btn-default dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false"> <i class="fa fa-pencil"></i> Edit <span class="caret"></span> </button> <ul class="dropdown-menu"> <li><a href="/cgi-bin/koha/cataloguing/additem.pl?op=edititem&biblionumber=[% item.biblionumber %]&itemnumber=[% item.itemnumber %]">Edit item</a></li> <li><a href="/cgi-bin/koha/cataloguing/addbiblio.pl?biblionumber=[% item.biblionumber %]">Edit record</a></li> </ul> </div>
  [%~ END %]"
]
