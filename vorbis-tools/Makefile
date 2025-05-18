# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2025 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=vorbis-tools
PKG_VERSION:=1.4.3
PKG_REV:=235540c05ad3f9cdc673ca09c237c9a9b5bda6eb
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/xiph/vorbis-tools.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=902914e01eafd9facd993f8a436ab21f6fa16addfc3626121785dfcf80388c35

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/vorbis-tools
	SECTION:=sound
	CATEGORY:=Sound
	DEPENDS:=+libogg +libvorbis +libflac
	TITLE:=vorbis-tools and nothing else
	URL:=http://xiph.org/vorbis/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/vorbis-tools/description
 oggdec, oggenc, ogginfo, vcut, vorbiscomment command line utilities.
endef

CONFIGURE_ARGS += \
	--disable-ogg123 \
	--disable-oggtest \
	--disable-vorbistest \
	--disable-curltest

define Package/vorbis-tools/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
endef

$(eval $(call BuildPackage,vorbis-tools))
