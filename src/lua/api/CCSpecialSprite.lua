
--------------------------------
-- @module CCSpecialSprite
-- @extend Sprite
-- @parent_module 

--------------------------------
-- @function [parent=#CCSpecialSprite] draw 
-- @param self
-- @param #cc.Renderer renderer
-- @param #mat4_table mat4
-- @param #bool bool
        
--------------------------------
-- @overload self, string, rect_table         
-- @overload self, string         
-- @function [parent=#CCSpecialSprite] initWithFile
-- @param self
-- @param #string str
-- @param #rect_table rect
-- @return bool#bool ret (retunr value: bool)

--------------------------------
-- @function [parent=#CCSpecialSprite] initWithSpriteFrameName 
-- @param self
-- @param #string str
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @function [parent=#CCSpecialSprite] initWithSpriteFrame 
-- @param self
-- @param #cc.SpriteFrame spriteframe
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @overload self, cc.__Dictionary         
-- @overload self         
-- @overload self, AnimatorModuleData         
-- @function [parent=#CCSpecialSprite] init
-- @param self
-- @param #AnimatorModuleData animatormoduledata
-- @return bool#bool ret (retunr value: bool)

--------------------------------
-- @overload self, cc.Texture2D, rect_table         
-- @overload self, cc.Texture2D         
-- @overload self, cc.Texture2D, rect_table, bool         
-- @function [parent=#CCSpecialSprite] initWithTexture
-- @param self
-- @param #cc.Texture2D texture2d
-- @param #rect_table rect
-- @param #bool bool
-- @return bool#bool ret (retunr value: bool)

--------------------------------
-- @overload self, cc.__Dictionary         
-- @overload self         
-- @overload self, AnimatorModuleData         
-- @function [parent=#CCSpecialSprite] create
-- @param self
-- @param #AnimatorModuleData animatormoduledata
-- @return CCSpecialSprite#CCSpecialSprite ret (retunr value: CCSpecialSprite)

--------------------------------
-- @overload self, cc.Node, int         
-- @overload self, cc.Node         
-- @overload self, cc.Node, int, int         
-- @overload self, cc.Node, int, string         
-- @function [parent=#CCSpecialSprite] addChild
-- @param self
-- @param #cc.Node node
-- @param #int int
-- @param #string str

--------------------------------
-- @function [parent=#CCSpecialSprite] setColor 
-- @param self
-- @param #color3b_table color3b
        
--------------------------------
-- @function [parent=#CCSpecialSprite] setOpacity 
-- @param self
-- @param #unsigned char char
        
return nil
