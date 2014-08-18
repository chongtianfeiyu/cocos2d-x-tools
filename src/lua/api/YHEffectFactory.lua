
--------------------------------
-- @module YHEffectFactory
-- @extend YHObject
-- @parent_module 

--------------------------------
-- @function [parent=#YHEffectFactory] effectSpriteForDefiner 
-- @param self
-- @param #YHEffectDefiner yheffectdefiner
-- @return Sprite#Sprite ret (return value: cc.Sprite)
        
--------------------------------
-- @function [parent=#YHEffectFactory] setAnimationCache 
-- @param self
-- @param #YHAnimationCache yhanimationcache
        
--------------------------------
-- @function [parent=#YHEffectFactory] cleanAll 
-- @param self
        
--------------------------------
-- @overload self, cc.__Dictionary         
-- @overload self, string, YHEffectDefiner         
-- @function [parent=#YHEffectFactory] addEffectDefiner
-- @param self
-- @param #string str
-- @param #YHEffectDefiner yheffectdefiner

--------------------------------
-- @function [parent=#YHEffectFactory] effectDefinerForKey 
-- @param self
-- @param #string str
-- @return YHEffectDefiner#YHEffectDefiner ret (return value: YHEffectDefiner)
        
--------------------------------
-- @function [parent=#YHEffectFactory] effectSpriteForKey 
-- @param self
-- @param #string str
-- @return Sprite#Sprite ret (return value: cc.Sprite)
        
--------------------------------
-- @function [parent=#YHEffectFactory] init 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @function [parent=#YHEffectFactory] cleanAllSprites 
-- @param self
        
--------------------------------
-- @function [parent=#YHEffectFactory] getAnimationCache 
-- @param self
-- @return YHAnimationCache#YHAnimationCache ret (return value: YHAnimationCache)
        
--------------------------------
-- @function [parent=#YHEffectFactory] cleanAllEffectDefiners 
-- @param self
        
--------------------------------
-- @function [parent=#YHEffectFactory] create 
-- @param self
-- @return YHEffectFactory#YHEffectFactory ret (return value: YHEffectFactory)
        
--------------------------------
-- @function [parent=#YHEffectFactory] YHEffectFactory 
-- @param self
        
return nil
