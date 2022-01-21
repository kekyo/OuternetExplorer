# Outernet Explorer

A funny old-style web browser stub, comes from Internet Explorer was genocided on Windows.

![Outernet Explorer icon](images/oexplore-128.png)

Download from: https://github.com/kekyo/OuternetExplorer/releases/download/1.0.0/oexplore.zip

## What's this?

A stub implementation for Internet Explorer ActiveX component (called `MSHTML`, `ShDocVw` and like).
It's simplest replacer for `iexplore.exe`.

## Usage

* Double-click `oexplore.exe` on the Explorer.
* Invokes from command-line:

```
C:\>oexplore.exe
```

### Options

Outenet Explorer could receive only target url like:

```
C:\>oexplore.exe https://google.com/
```

Unfortunately, the url will inspect inside of Internet Explorer component, and maybe shows up both IE **AND** Edge2...

## License

MIT
