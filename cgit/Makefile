#
# Copyright (C) 2009-2018 OpenWrt.org
# Copyright (C) 2018-2022 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cgit
PKG_VERSION:=1.2.3
PKG_RELEASE:=3
PKG_SOURCE_DATE:=2021-06-08
PKG_SOURCE_VERSION:=5258c297ba6fb604ae1415fbc19a3fe42457e49e

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://git.zx2c4.com/cgit
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_SOURCE_DATE).tar.xz
PKG_MIRROR_HASH:=4cc56d39e5ef73eca843f8d431c249e7aef2ef551f07968317b2cb719a56f866

PKG_LICENSE:=GPL-2.0-or-later
PKG_LICENSE_FILES:=COPYING

PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/cgit
	TITLE:=Web interface (cgi) for Git repositories, written in C
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Version Control Systems
	DEPENDS:=+libcharset @HAS_LUAJIT_ARCH +luajit +libopenssl +libpcre2 +zlib $(ICONV_DEPENDS) $(INTL_DEPENDS)
	URL:=https://git.zx2c4.com/cgit/
	MAINTAINER:=Troels Gram [https://github.com/tgram75]
endef

define Package/cgit/description
 Cgit is a web interface (cgi) for Git repositories, written in C
 This is an attempt to create a fast web interface for the Git
 SCM, using a built-in cache to decrease server I/O pressure.
endef

define Build/Configure
	( cd $(PKG_BUILD_DIR)/git;  \
		make configure; \
		./configure \
			$(CONFIGURE_ARGS) \
			--with-libpcre2 \
			--with-gitconfig=/opt/etc/gitconfig \
			--with-gitattributes=/opt/etc/gitattributes \
			--with-pager=/opt/bin/less \
			--with-editor=/opt/bin/vi \
			--with-perl=/opt/bin/perl \
			--with-python=/opt/bin/python \
			--with-iconv=$(ICONV_PREFIX) \
			CFLAGS="$(TARGET_CFLAGS)" \
			CPPFLAGS="$(TARGET_CPPFLAGS)" \
			LDFLAGS="$(TARGET_LDFLAGS)" \
	)
endef

define Package/cgit/install
	$(INSTALL_DIR) $(1)
	$(CP) $(PKG_INSTALL_DIR)/opt $(1)/
endef

$(eval $(call BuildPackage,cgit))
