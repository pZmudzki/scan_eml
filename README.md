# scan_eml

.eml file rules:

- file can't contain any letters besides those in english alphabet

- file's content MUST be in a valid standard form, for example:
  Not valid:
  Content-Disposition: attachment;
  filename="file.pdf"
  (This isn't in standart because it should be in a single line)
  Valid:
  Content-Disposition: attachment; filename="file.pdf"

note: formatting pdf files to plain text is too difficult to accomplish
