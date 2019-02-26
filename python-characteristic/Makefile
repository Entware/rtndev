#
# Copyright (C) 2008-2015 OpenWrt
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=characteristic
PKG_VERSION:=14.3.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://files.pythonhosted.org/packages/dc/66/54b7a4758ea44fbc93895c7745060005272560fb2c356f2a6f7448ef9a80
PKG_HASH:=ded68d4e424115ed44e5c83c2a901a0b6157a959079d7591d92106ffd3ada380

PKG_BUILD_DEPENDS:=python

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/python-characteristic
  SUBMENU:=Python
  SECTION:=lang
  CATEGORY:=Languages
  TITLE:=python-characteristic
  URL:=https://characteristic.readthedocs.org/
  DEPENDS:=+python
endef

define Package/python-characteristic/description
  characteristic is an MIT-licensed Python package with class decorators that ease the chores of implementing
  the most common attribute-related object protocols.
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
endef

define Package/python-characteristic/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
	    $(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
	    $(1)$(PYTHON_PKG_DIR)
endef

$(eval $(call BuildPackage,python-characteristic))
