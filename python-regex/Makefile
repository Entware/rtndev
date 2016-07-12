#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-regex
PKG_VERSION:=0.1.20160619
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION).orig.tar.gz
PKG_SOURCE_URL:=ftp://ftp.debian.org/debian/pool/main/p/$(PKG_NAME)
PKG_MD5SUM:=d10f923cdda1a6cb674bbecc9440f42b

PKG_BUILD_DIR:=$(BUILD_DIR)/regex-2016.06.19

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
