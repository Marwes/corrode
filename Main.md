```haskell
module Main where

import Control.Monad.Trans.Class (lift)
import Control.Monad.Trans.Except (ExceptT, runExceptT)
import System.Environment (getArgs)
import System.Exit (die)

import Language.Rust.Main (mainWithArgs)

main :: IO ()
main = dieOnError $ lift getArgs >>= mainWithArgs
```

When the pipeline ends, we need to check whether it resulted in an
error. If so, we call `die` to print the error message to `stderr` and
exit with a failure status code.

```haskell
dieOnError :: ExceptT String IO a -> IO a
dieOnError m = do
    result <- runExceptT m
    case result of
        Left err -> die err
        Right a -> return a
```