
--------------------------------
-- @module YHByteArray
-- @extend YHObject,YHIByteBuffer
-- @parent_module 

--------------------------------
-- @function [parent=#YHByteArray] readUnsignedShort 
-- @param self
-- @return unsigned short#unsigned short ret (return value: unsigned short)
        
--------------------------------
-- @function [parent=#YHByteArray] setWriterIndex 
-- @param self
-- @param #unsigned int int
        
--------------------------------
-- @function [parent=#YHByteArray] getBoolean 
-- @param self
-- @param #unsigned int int
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @function [parent=#YHByteArray] readFloat 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- @function [parent=#YHByteArray] setCapacity 
-- @param self
-- @param #unsigned int int
        
--------------------------------
-- @function [parent=#YHByteArray] setUnsignedChar 
-- @param self
-- @param #unsigned int int
-- @param #unsigned char char
        
--------------------------------
-- @function [parent=#YHByteArray] setUnsignedInt 
-- @param self
-- @param #unsigned int int
-- @param #unsigned int int
        
--------------------------------
-- @function [parent=#YHByteArray] writeDouble 
-- @param self
-- @param #double double
        
--------------------------------
-- @function [parent=#YHByteArray] readableBytes 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- @function [parent=#YHByteArray] writeBoolean 
-- @param self
-- @param #bool bool
        
--------------------------------
-- @function [parent=#YHByteArray] readUnsignedChar 
-- @param self
-- @return unsigned char#unsigned char ret (return value: unsigned char)
        
--------------------------------
-- @function [parent=#YHByteArray] getShort 
-- @param self
-- @param #unsigned int int
-- @return short#short ret (return value: short)
        
--------------------------------
-- @function [parent=#YHByteArray] discardReadBytes 
-- @param self
        
--------------------------------
-- @function [parent=#YHByteArray] writeShort 
-- @param self
-- @param #short short
        
--------------------------------
-- @function [parent=#YHByteArray] getReaderIndex 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- @overload self, unsigned int         
-- @overload self         
-- @function [parent=#YHByteArray] isReadabled
-- @param self
-- @param #unsigned int int
-- @return bool#bool ret (retunr value: bool)

--------------------------------
-- @overload self, char, unsigned int         
-- @overload self, YHIByteBuffer, unsigned int         
-- @function [parent=#YHByteArray] writeBytes
-- @param self
-- @param #YHIByteBuffer yhibytebuffer
-- @param #unsigned int int

--------------------------------
-- @function [parent=#YHByteArray] getWriterIndex 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- @function [parent=#YHByteArray] readBoolean 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @function [parent=#YHByteArray] setReaderIndex 
-- @param self
-- @param #unsigned int int
        
--------------------------------
-- @function [parent=#YHByteArray] getUnsignedChar 
-- @param self
-- @param #unsigned int int
-- @return unsigned char#unsigned char ret (return value: unsigned char)
        
--------------------------------
-- @function [parent=#YHByteArray] init 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @function [parent=#YHByteArray] getCapacity 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- @overload self, char, unsigned int         
-- @overload self, YHIByteBuffer, unsigned int         
-- @function [parent=#YHByteArray] readBytes
-- @param self
-- @param #YHIByteBuffer yhibytebuffer
-- @param #unsigned int int

--------------------------------
-- @function [parent=#YHByteArray] getOrder 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, unsigned int, char, unsigned int, unsigned int         
-- @overload self, unsigned int, YHIByteBuffer, unsigned int, unsigned int         
-- @function [parent=#YHByteArray] getBytes
-- @param self
-- @param #unsigned int int
-- @param #YHIByteBuffer yhibytebuffer
-- @param #unsigned int int
-- @param #unsigned int int

--------------------------------
-- @overload self, unsigned int, char, unsigned int, unsigned int         
-- @overload self, unsigned int, YHIByteBuffer, unsigned int, unsigned int         
-- @function [parent=#YHByteArray] setBytes
-- @param self
-- @param #unsigned int int
-- @param #YHIByteBuffer yhibytebuffer
-- @param #unsigned int int
-- @param #unsigned int int

--------------------------------
-- @function [parent=#YHByteArray] getUnsignedInt 
-- @param self
-- @param #unsigned int int
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- @function [parent=#YHByteArray] readShort 
-- @param self
-- @return short#short ret (return value: short)
        
--------------------------------
-- @function [parent=#YHByteArray] readUnsignedInt 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- @function [parent=#YHByteArray] writeUnsignedInt 
-- @param self
-- @param #unsigned int int
        
--------------------------------
-- @function [parent=#YHByteArray] readInt 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @function [parent=#YHByteArray] writeChar 
-- @param self
-- @param #char char
        
--------------------------------
-- @function [parent=#YHByteArray] getDouble 
-- @param self
-- @param #unsigned int int
-- @return double#double ret (return value: double)
        
--------------------------------
-- @function [parent=#YHByteArray] setShort 
-- @param self
-- @param #unsigned int int
-- @param #short short
        
--------------------------------
-- @function [parent=#YHByteArray] setUnsignedShort 
-- @param self
-- @param #unsigned int int
-- @param #unsigned short short
        
--------------------------------
-- @function [parent=#YHByteArray] setOrder 
-- @param self
-- @param #int yhbyteorder
        
--------------------------------
-- @function [parent=#YHByteArray] getInt 
-- @param self
-- @param #unsigned int int
-- @return int#int ret (return value: int)
        
--------------------------------
-- @function [parent=#YHByteArray] setInt 
-- @param self
-- @param #unsigned int int
-- @param #int int
        
--------------------------------
-- @function [parent=#YHByteArray] readChar 
-- @param self
-- @return char#char ret (return value: char)
        
--------------------------------
-- @function [parent=#YHByteArray] readDouble 
-- @param self
-- @return double#double ret (return value: double)
        
--------------------------------
-- @function [parent=#YHByteArray] getBuffer 
-- @param self
-- @return unsigned char#unsigned char ret (return value: unsigned char)
        
--------------------------------
-- @function [parent=#YHByteArray] getFloat 
-- @param self
-- @param #unsigned int int
-- @return float#float ret (return value: float)
        
--------------------------------
-- @function [parent=#YHByteArray] autorelease 
-- @param self
-- @return Ref#Ref ret (return value: cc.Ref)
        
--------------------------------
-- @function [parent=#YHByteArray] setFloat 
-- @param self
-- @param #unsigned int int
-- @param #float float
        
--------------------------------
-- @function [parent=#YHByteArray] clear 
-- @param self
        
--------------------------------
-- @function [parent=#YHByteArray] setDouble 
-- @param self
-- @param #unsigned int int
-- @param #double double
        
--------------------------------
-- @function [parent=#YHByteArray] writeUnsignedChar 
-- @param self
-- @param #unsigned char char
        
--------------------------------
-- @function [parent=#YHByteArray] setChar 
-- @param self
-- @param #unsigned int int
-- @param #char char
        
--------------------------------
-- @function [parent=#YHByteArray] writeableBytes 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- @function [parent=#YHByteArray] writeFloat 
-- @param self
-- @param #float float
        
--------------------------------
-- @function [parent=#YHByteArray] writeInt 
-- @param self
-- @param #int int
        
--------------------------------
-- @function [parent=#YHByteArray] getUnsignedShort 
-- @param self
-- @param #unsigned int int
-- @return unsigned short#unsigned short ret (return value: unsigned short)
        
--------------------------------
-- @function [parent=#YHByteArray] writeUnsignedShort 
-- @param self
-- @param #unsigned short short
        
--------------------------------
-- @overload self, unsigned int         
-- @overload self         
-- @function [parent=#YHByteArray] isWriteable
-- @param self
-- @param #unsigned int int
-- @return bool#bool ret (retunr value: bool)

--------------------------------
-- @function [parent=#YHByteArray] setBoolean 
-- @param self
-- @param #unsigned int int
-- @param #bool bool
        
--------------------------------
-- @function [parent=#YHByteArray] getChar 
-- @param self
-- @param #unsigned int int
-- @return char#char ret (return value: char)
        
--------------------------------
-- @function [parent=#YHByteArray] YHByteArray 
-- @param self
        
return nil
