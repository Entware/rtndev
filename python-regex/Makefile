#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-regex
PKG_VERSION:=2019.02.21
PKG_RELEASE:=1

PKG_SOURCE:=regex-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://files.pythonhosted.org/packages/d0/b5/79b2b7d19a0e1f94f2b11e73ea9682a5bf9d78bcf25fb278955157acdf33
PKG_HASH:=587bd4cad11c7294f89799c45778abca271d7c6668a0e85c41a6dbfa8096f9bb

PKG_BUILD_DIR:=$(BUILD_DIR)/regex-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/python-regex
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python-light
	TITLE:=python-regexp
	URL:=https://bitbucket.org/mrabarnett/mrab-regex
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/python-regex/description
 This new regex implementation is intended eventually to replace Python’s current re module implementation. 
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
endef

$(eval $(call PyPackage,python-regex))
$(eval $(call BuildPackage,python-regex))
