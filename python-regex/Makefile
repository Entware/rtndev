#
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-regex
PKG_VERSION:=2018.02.08
PKG_RELEASE:=1

PKG_SOURCE:=regex-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://pypi.python.org/packages/be/32/429382300a06eaa12094563ea40665b5a4ecfce50dcbece06200ae703c07
PKG_HASH:=2353c0e983c4029caf32016f1dddef623c3117ac282a818468c6d2f5d541698d

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
