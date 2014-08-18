
--------------------------------
-- @module YHUIDecimalNumber
-- @extend YHISpriteNumber
-- @parent_module 

--------------------------------
-- @overload self, string         
-- @overload self, unsigned int         
-- @function [parent=#YHUIDecimalNumber] setNumber
-- @param self
-- @param #unsigned int int

--------------------------------
-- @function [parent=#YHUIDecimalNumber] layout 
-- @param self
        
--------------------------------
-- @function [parent=#YHUIDecimalNumber] setColor 
-- @param self
-- @param #color3b_table color3b
        
--------------------------------
-- @function [parent=#YHUIDecimalNumber] setInterval 
-- @param self
-- @param #float float
        
--------------------------------
-- @function [parent=#YHUIDecimalNumber] setPlaces 
-- @param self
-- @param #unsigned int int
        
--------------------------------
-- @function [parent=#YHUIDecimalNumber] setIconInterval 
-- @param self
-- @param #float float
        
--------------------------------
-- @function [parent=#YHUIDecimalNumber] setOpacity 
-- @param self
-- @param #unsigned char char
        
--------------------------------
-- @function [parent=#YHUIDecimalNumber] getNumberFontWidth 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- @overload self, cc.SpriteFrame, size_table, float, cc.Sprite         
-- @overload self, cc.Texture2D, vec2_table, size_table, float, cc.Sprite         
-- @overload self, char, size_table, float, cc.Sprite         
-- @function [parent=#YHUIDecimalNumber] init
-- @param self
-- @param #cc.Texture2D texture2d
-- @param #vec2_table vec2
-- @param #size_table size
-- @param #float float
-- @param #cc.Sprite sprite
-- @return bool#bool ret (retunr value: bool)

--------------------------------
-- @function [parent=#YHUIDecimalNumber] setAlignType 
-- @param self
-- @param #int yhspritenumber_aligntype
        
--------------------------------
-- @function [parent=#YHUIDecimalNumber] setIcon 
-- @param self
-- @param #cc.Sprite sprite
        
--------------------------------
-- @overload self, cc.SpriteFrame, size_table, float, cc.Sprite         
-- @overload self, cc.Texture2D, vec2_table, size_table, float, cc.Sprite         
-- @overload self, char, size_table, float, cc.Sprite         
-- @function [parent=#YHUIDecimalNumber] create
-- @param self
-- @param #cc.Texture2D texture2d
-- @param #vec2_table vec2
-- @param #size_table size
-- @param #float float
-- @param #cc.Sprite sprite
-- @return YHUIDecimalNumber#YHUIDecimalNumber ret (retunr value: YHUIDecimalNumber)

--------------------------------
-- @function [parent=#YHUIDecimalNumber] YHUIDecimalNumber 
-- @param self
        
return nil
