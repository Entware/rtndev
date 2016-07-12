#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-pillow
PKG_VERSION:=3.3.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/python-pillow/Pillow/archive
PKG_MD5SUM:=56c2f864d9a64cb5491410024d755229

PKG_BUILD_DIR:=$(BUILD_DIR)/Pillow-$(PKG_VERSION)
PKG_BUILD_DEPENDS:=python python-setuptools

PKG_UNPACK=$(HOST_TAR) -C $(PKG_BUILD_DIR) --strip-components=1 -xf $(DL_DIR)/$(PKG_SOURCE)

include $(INCLUDE_DIR)/package.mk
$(call include_mk, python-package.mk)

define Package/python-pillow
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python +libfreetype +libjpeg +zlib +lcms
	CONFLICTS:=python-imglib
	TITLE:=TITLE:=Python Imaging Library (PIL fork)
	URL:=http://python-pillow.org/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/python-pillow/description
 Pillow is the “friendly PIL fork” by Alex Clark and Contributors.
 PIL is the Python Imaging Library by Fredrik Lundh and Contributors.
endef

define Build/Compile
	$(call Build/Compile/PyMod,., \
		build_ext --disable-jpeg2000 --disable-webp --disable-webpmux \
		install --prefix="/opt" --root="$(PKG_INSTALL_DIR)", \
	)
endef

define Package/python-pillow/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) \
		$(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
		$(1)$(PYTHON_PKG_DIR)/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
endef

$(eval $(call BuildPackage,python-pillow))
