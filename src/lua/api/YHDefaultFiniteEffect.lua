
--------------------------------
-- @module YHDefaultFiniteEffect
-- @extend CCSprite,YHIFiniteEffect
-- @parent_module 

--------------------------------
-- @overload self, cc.__Array, float         
-- @overload self, cc.FiniteTimeAction         
-- @overload self, float         
-- @overload self         
-- @function [parent=#YHDefaultFiniteEffect] reset
-- @param self
-- @param #cc.__Array __array
-- @param #float float

--------------------------------
-- @function [parent=#YHDefaultFiniteEffect] getDelegate 
-- @param self
-- @return YHFiniteEffectDelegate#YHFiniteEffectDelegate ret (return value: YHFiniteEffectDelegate)
        
--------------------------------
-- @function [parent=#YHDefaultFiniteEffect] setColor 
-- @param self
-- @param #color3b_table color3b
        
--------------------------------
-- @function [parent=#YHDefaultFiniteEffect] resetBasicParams 
-- @param self
        
--------------------------------
-- @function [parent=#YHDefaultFiniteEffect] setParent 
-- @param self
-- @param #cc.Node node
        
--------------------------------
-- @function [parent=#YHDefaultFiniteEffect] setDelegate 
-- @param self
-- @param #YHFiniteEffectDelegate yhfiniteeffectdelegate
        
--------------------------------
-- @function [parent=#YHDefaultFiniteEffect] autoRemoveFromParent 
-- @param self
        
--------------------------------
-- @function [parent=#YHDefaultFiniteEffect] isActive 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @overload self, char         
-- @overload self         
-- @overload self, char, rect_table         
-- @function [parent=#YHDefaultFiniteEffect] create
-- @param self
-- @param #char char
-- @param #rect_table rect
-- @return YHDefaultFiniteEffect#YHDefaultFiniteEffect ret (retunr value: YHDefaultFiniteEffect)

--------------------------------
-- @overload self, cc.Texture2D, rect_table         
-- @overload self, cc.Texture2D         
-- @function [parent=#YHDefaultFiniteEffect] createWithTexture
-- @param self
-- @param #cc.Texture2D texture2d
-- @param #rect_table rect
-- @return YHDefaultFiniteEffect#YHDefaultFiniteEffect ret (retunr value: YHDefaultFiniteEffect)

--------------------------------
-- @function [parent=#YHDefaultFiniteEffect] createWithSpriteFrameName 
-- @param self
-- @param #char char
-- @return YHDefaultFiniteEffect#YHDefaultFiniteEffect ret (return value: YHDefaultFiniteEffect)
        
--------------------------------
-- @function [parent=#YHDefaultFiniteEffect] createWithSpriteFrame 
-- @param self
-- @param #cc.SpriteFrame spriteframe
-- @return YHDefaultFiniteEffect#YHDefaultFiniteEffect ret (return value: YHDefaultFiniteEffect)
        
return nil
