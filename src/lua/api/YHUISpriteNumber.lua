
--------------------------------
-- @module YHUISpriteNumber
-- @extend YHISpriteNumber
-- @parent_module 

--------------------------------
-- @overload self, string         
-- @overload self, unsigned int         
-- @function [parent=#YHUISpriteNumber] setNumber
-- @param self
-- @param #unsigned int int

--------------------------------
-- @function [parent=#YHUISpriteNumber] layout 
-- @param self
        
--------------------------------
-- @function [parent=#YHUISpriteNumber] setColor 
-- @param self
-- @param #color3b_table color3b
        
--------------------------------
-- @function [parent=#YHUISpriteNumber] setInterval 
-- @param self
-- @param #float float
        
--------------------------------
-- @function [parent=#YHUISpriteNumber] setIconInterval 
-- @param self
-- @param #float float
        
--------------------------------
-- @function [parent=#YHUISpriteNumber] setOpacity 
-- @param self
-- @param #unsigned char char
        
--------------------------------
-- @function [parent=#YHUISpriteNumber] getNumberFontWidth 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- @overload self, cc.SpriteFrame, size_table, float         
-- @overload self, cc.Texture2D, vec2_table, size_table, float         
-- @overload self, char, size_table, float         
-- @function [parent=#YHUISpriteNumber] init
-- @param self
-- @param #cc.Texture2D texture2d
-- @param #vec2_table vec2
-- @param #size_table size
-- @param #float float
-- @return bool#bool ret (retunr value: bool)

--------------------------------
-- @function [parent=#YHUISpriteNumber] getNumbers 
-- @param self
-- @return __Array#__Array ret (return value: cc.__Array)
        
--------------------------------
-- @function [parent=#YHUISpriteNumber] setNumberOffset 
-- @param self
-- @param #vec2_table vec2
        
--------------------------------
-- @function [parent=#YHUISpriteNumber] setAlignType 
-- @param self
-- @param #int yhspritenumber_aligntype
        
--------------------------------
-- @function [parent=#YHUISpriteNumber] setIcon 
-- @param self
-- @param #cc.Sprite sprite
        
--------------------------------
-- @overload self, cc.SpriteFrame, size_table, float         
-- @overload self, cc.Texture2D, vec2_table, size_table, float         
-- @overload self, char, size_table, float         
-- @function [parent=#YHUISpriteNumber] create
-- @param self
-- @param #cc.Texture2D texture2d
-- @param #vec2_table vec2
-- @param #size_table size
-- @param #float float
-- @return YHUISpriteNumber#YHUISpriteNumber ret (retunr value: YHUISpriteNumber)

return nil
