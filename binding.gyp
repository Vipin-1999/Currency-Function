{
  "targets": [
    {
      "target_name": "Currency",
      "sources": [ "currency.cpp", "currency_wrap.cxx" ],
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ]
    }
  ]
}