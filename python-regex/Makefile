#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-regex
PKG_VERSION:=2017.04.05
PKG_RELEASE:=1

PKG_SOURCE:=regex-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://pypi.python.org/packages/36/62/c0c0d762ffd4ffaf39f372eb8561b8d491a11ace5a7884610424a8b40f95
PKG_MD5SUM:=ab3bcd0b1c1a4f6e3315e1861477642b

PKG_BUILD_DIR:=$(BUILD_DIR)/regex-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
$(call include_mk, python-package.mk)

define Package/python-regex
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python-light
	TITLE:=python-regexp
	URL:=https://bitbucket.org/mrabarnett/mrab-regex
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/python-regex/description
 This new regex implementation is intended eventually to replace Python’s current re module implementation. 
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
endef

$(eval $(call PyPackage,python-regex))
$(eval $(call BuildPackage,python-regex))
